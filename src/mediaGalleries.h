#ifndef _NODE_MEDIA_GALLERIES__H_
#define _NODE_MEDIA_GALLERIES__H_

#include <string>

#include <node.h>
#include <v8.h>

namespace mediaGalleries {
namespace impl {

v8::Local<v8::Array> getPictureGalleries(v8::Isolate* isolate);

} // namespace impl
} // namespace mediaGalleries

#endif /*_NODE_MEDIA_GALLERIES__H_*/