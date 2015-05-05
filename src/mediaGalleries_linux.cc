#include <string>

#include <node.h>
#include <v8.h>

#include "linux/xdg-user-dirs.h"
#include "mediaGalleries.h"

using std::string;
using namespace v8;

namespace mediaGalleries {
namespace impl {

const string XDG_USER_DIRS[] = {
  "PICTURES",
  "DOCUMENTS"
};
const unsigned int XDG_USER_DIRS_SIZE = 2;

void initialize() {}
void unInitialize() {}

Local<Array> getPictureGalleries(Isolate* isolate) {

    Local<Array> galleries = Array::New(isolate, XDG_USER_DIRS_SIZE);
    for (unsigned int i = 0; i < XDG_USER_DIRS_SIZE; ++i) {
        const char* xdg_user_dir = XDG_USER_DIRS[i].c_str();
        char* path = xdg_user_dir_lookup(xdg_user_dir);
        string path_cxx = path;
        string name = path_cxx.substr(path_cxx.rfind("/") + 1);
        Local<Object> folder = Object::New(isolate);
        folder->Set(String::NewFromUtf8(isolate, "id"), String::NewFromUtf8(isolate, path));
        folder->Set(String::NewFromUtf8(isolate, "type"), String::NewFromUtf8(isolate, xdg_user_dir));
        folder->Set(String::NewFromUtf8(isolate, "name"), String::NewFromUtf8(isolate, name.c_str()));
        folder->Set(String::NewFromUtf8(isolate, "path"), String::NewFromUtf8(isolate, path));
        free(path);
        galleries->Set(i, folder);
    }

    return galleries;
}

} // namespace impl
} // namespace mediaGalleries