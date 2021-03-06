#include <nan.h>

#ifndef __FF_FF_H__
#define __FF_FF_H__

#define FF_VAL v8::Local<v8::Value>
#define FF_OBJ v8::Local<v8::Object>
#define FF_ARR v8::Local<v8::Array>
#define FF_FUNC v8::Local<v8::Function>

#define FF_NEW_STRING(val) Nan::New(val).ToLocalChecked()
#define FF_NEW_OBJ Nan::New<v8::Object>
#define FF_NEW_ARRAY Nan::New<v8::Array>

#define FF_CAST_BOOL(val) val->ToBoolean(Nan::GetCurrentContext()).ToLocalChecked()->Value()
#define FF_CAST_NUMBER(val) val->ToNumber(Nan::GetCurrentContext()).ToLocalChecked()->Value()
#define FF_CAST_FLOAT(val) static_cast<float>(val->ToNumber(Nan::GetCurrentContext()).ToLocalChecked()->Value())
#define FF_CAST_UINT(val) val->ToUint32(Nan::GetCurrentContext()).ToLocalChecked()->Value()
#define FF_CAST_INT(val) val->ToInt32(Nan::GetCurrentContext()).ToLocalChecked()->Value()
#define FF_CAST_STRING(s) std::string(*Nan::Utf8String(s->ToString(Nan::GetCurrentContext()).ToLocalChecked()))
#define FF_CAST_OBJ(val) Nan::To<v8::Object>(val).ToLocalChecked()
#define FF_CAST_ARRAY(val) v8::Local<v8::Array>::Cast(val)
#define FF_CAST_FUNC(f) Nan::To<v8::Function>(f).ToLocalChecked()

#define FF_IS_BOOL(val) val->IsBoolean()
#define FF_IS_NUMBER(val) val->IsNumber()
#define FF_IS_UINT(val) val->IsUint32()
#define FF_IS_INT(val) val->IsInt32()
#define FF_IS_STRING(val) val->IsString()
#define FF_IS_ARRAY(val) val->IsArray()
#define FF_IS_OBJ(val) ( val->IsObject() && !FF_IS_ARRAY(val))
#define FF_IS_FUNC(val) val->IsFunction()

#define FF_IS_INSTANCE(ctor, obj) Nan::New(ctor)->HasInstance(obj)
#define FF_HAS(obj, prop) Nan::HasOwnProperty(obj, FF_NEW_STRING(prop)).FromJust()

#define FF_RETURN(val) info.GetReturnValue().Set(val)
#define FF_THROW(msg) return Nan::ThrowError(FF_NEW_STRING(std::string(ff_methodName) + " - " + std::string(msg)));
#define FF_THROWTYPE(msg) return Nan::ThrowTypeError(FF_NEW_STRING(std::string(ff_methodName) + " - " + std::string(msg)));
#define FF_THROWCPP(msg) throw std::runtime_error(std::string(ff_methodName) + " - " + std::string(msg));

#define FF_METHOD_CONTEXT(methodName) std::string ff_methodName = methodName;
#define FF_EXTEND_METHOD_CONTEXT(extension) ff_methodName.append(std::string(extension))

#endif
