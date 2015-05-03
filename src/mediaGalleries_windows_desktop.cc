#include <string>

#include <Windows.h>
#include <KnownFolders.h>
#include <ShObjidl.h>
#include <Shlwapi.h>

#include <node.h>
#include <v8.h>

#include "mediaGalleries.h"

using namespace v8;

namespace mediaGalleries {
namespace impl {

Local<Array> getPictureGalleries(Isolate* isolate) {

    IShellLibrary *picturesLibrary;

    HRESULT
    hr = SHLoadLibraryFromKnownFolder(FOLDERID_PicturesLibrary,
                                      STGM_READ,
                                      IID_PPV_ARGS(&picturesLibrary));

    // picturesLibrary now points to the user's picture library


    IShellItemArray *pictureFolders;
    picturesLibrary->GetFolders(LFF_FORCEFILESYSTEM, IID_PPV_ARGS(&pictureFolders));

    // pictureFolders now contains an array of Shell items that
    // represent the folders found in the user's pictures library

    const int argc = 1;
    Local<Array> arr = Array::New(isolate, argc);
    arr->Set(0, String::NewFromUtf8(isolate, "test1"));
    Local<Value> argv[argc] = { arr };
    return arr;
}

} // namespace impl
} // namespace mediaGalleries