#include <nan.h>

#ifndef __FF_FF_H__
#define __FF_FF_H__

typedef unsigned int uint;

#define FF_VAL v8::Local<v8::Value>
#define FF_OBJ v8::Local<v8::Object>
#define FF_ARR v8::Local<v8::Array>

#define FF_NEW_VAL(val) Nan::New(val).ToLocalChecked()
#define FF_NEW_OBJ Nan::New<v8::Object>
#define FF_NEW_ARR Nan::New<v8::Array>

#define FF_TO_STRING(s) std::string(*Nan::Utf8String(s->ToString()))
#define FF_CAST_OBJ(val) Nan::To<v8::Object>(val).ToLocalChecked()
#define FF_CAST_ARRAY(val) v8::Local<v8::Array>::Cast(val)

#define FF_IS_BOOL(val) val->IsBoolean()
#define FF_CAST_BOOL(val) val->BooleanValue()
#define FF_IS_NUMBER(val) val->IsNumber()
#define FF_CAST_NUMBER(val) val->NumberValue()
#define FF_IS_UINT(val) val->IsUint32()
#define FF_CAST_UINT(val) val->Uint32Value()
#define FF_IS_INT(val) val->IsInt32()
#define FF_CAST_INT(val) val->Int32Value()
#define FF_IS_STRING(val) val->IsString()
#define FF_IS_INSTANCE(ctor, obj) Nan::New(ctor)->HasInstance(obj)
#define FF_HAS(obj, prop) Nan::HasOwnProperty(obj, FF_NEW_VAL(prop)).FromJust()

#define FF_RETURN(val) info.GetReturnValue().Set(val)
#define FF_METHOD_CONTEXT(methodName) std::string ff_methodName = methodName;
#define FF_THROW(msg) return Nan::ThrowError(FF_NEW_VAL(std::string(ff_methodName) + " - " + std::string(msg)));

#endif