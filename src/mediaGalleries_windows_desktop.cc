#include <cwchar>
#include <iostream>

#include <Windows.h>
#include <winnt.h>
#include <KnownFolders.h>
#include <ShObjidl.h>
#include <Shlwapi.h>
#include <objbase.h>

#include <node.h>
#include <v8.h>

#include "mediaGalleries.h"

using std::wprintf;
using namespace v8;

namespace mediaGalleries {
namespace impl {

void initialize() {
    CoInitialize(NULL);
}

void unInitialize() {
    CoUninitialize();
}

Local<Array> getPictureGalleries(Isolate* isolate) {

    HRESULT res = S_OK;

    IShellLibrary *picturesLibrary;
    res = SHLoadLibraryFromKnownFolder(FOLDERID_PicturesLibrary,
                                       STGM_READ,
                                       IID_PPV_ARGS(&picturesLibrary));

    IShellItemArray *pictureFolders;
    picturesLibrary->GetFolders(LFF_FORCEFILESYSTEM, IID_PPV_ARGS(&pictureFolders));


    DWORD pictureFoldersCount;
    pictureFolders->GetCount(&pictureFoldersCount);

    Local<Array> galleries = Array::New(isolate, (int) pictureFoldersCount);

    for (unsigned long i = 0; i < pictureFoldersCount; ++i) {
        IShellItem *pictureFolder;
        LPWSTR name;
        char *name_c;
        LPWSTR path;
        char *path_c;

        pictureFolders->GetItemAt(i, &pictureFolder);

        pictureFolder->GetDisplayName(SIGDN_NORMALDISPLAY, &name);
        name_c = new char[wcslen(name) + 1];
        wsprintfA(name_c, "%S", name);

        pictureFolder->GetDisplayName(SIGDN_FILESYSPATH, &path);
        path_c = new char[wcslen(path) + 1];
        wsprintfA(path_c, "%S", path);

        Local<Object> folder = Object::New(isolate);
        folder->Set(String::NewFromUtf8(isolate, "id"), String::NewFromUtf8(isolate, path_c));
        folder->Set(String::NewFromUtf8(isolate, "type"), String::NewFromUtf8(isolate, "PICTURES"));
        folder->Set(String::NewFromUtf8(isolate, "name"), String::NewFromUtf8(isolate, name_c));
        folder->Set(String::NewFromUtf8(isolate, "path"), String::NewFromUtf8(isolate, path_c));
        galleries->Set(i, folder);

        delete path_c;
        delete name_c;
    }

    return galleries;

}

} // namespace impl
} // namespace mediaGalleries