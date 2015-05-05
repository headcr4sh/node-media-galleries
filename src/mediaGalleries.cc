#include <node.h>
#include <v8.h>

#include "mediaGalleries.h"

using namespace v8;

void getPictureGalleries(const FunctionCallbackInfo<Value>& args) {

    mediaGalleries::impl::initialize();

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

    try {
        Local<Value> argv[1] = { mediaGalleries::impl::getPictureGalleries(isolate) };
        successCallback->Call(isolate->GetCurrentContext()->Global(), 1, argv);
    } catch (int code) {
        Local<Object> error = Object::New(isolate);
        error->Set(String::NewFromUtf8(isolate, "code"), Number::New(isolate, code));
        Local<Value> argv[1] = { error };
        errorCallback->Call(isolate->GetCurrentContext()->Global(), 1, argv);
    }

    mediaGalleries::impl::unInitialize();

}

void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "getPictureGalleries", getPictureGalleries);
}

NODE_MODULE(mediaGalleries, init);