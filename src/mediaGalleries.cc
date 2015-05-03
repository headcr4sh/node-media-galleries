#include <node.h>
#include <v8.h>

#include "mediaGalleries.h"

using namespace v8;

void getPictureGalleries(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

     if (args.Length() < 2) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
      }

      if (!args[0]->IsFunction() || !args[1]->IsFunction()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments")));
        return;
      }

    Local<Function> successCallback = Local<Function>::Cast(args[0]);
    Local<Function> errorCallback = Local<Function>::Cast(args[1]);

    Local<Value> argv[1] = { mediaGalleries::impl::getPictureGalleries(isolate) };
    successCallback->Call(isolate->GetCurrentContext()->Global(), 1, argv);

}

void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "getPictureGalleries", getPictureGalleries);
}

NODE_MODULE(mediaGalleries, init);