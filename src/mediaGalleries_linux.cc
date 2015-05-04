#include <string>

#include <node.h>
#include <v8.h>

#include "linux/xdg-user-dirs.h"
#include "mediaGalleries.h"

using namespace v8;

namespace mediaGalleries {
namespace impl {

Local<Array> getPictureGalleries(Isolate* isolate) {

	char* picturesPath = xdg_user_dir_lookup("PICTURES");

    const int argc = 1;
    Local<Array> arr = Array::New(isolate, argc);
    arr->Set(0, String::NewFromUtf8(isolate, picturesPath));
    free(picturesPath);
    return arr;
}

} // namespace impl
} // namespace mediaGalleries