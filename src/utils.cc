#include <stdlib.h>
#include "utils.h"

void FreeDataCallback(char *data, void *hint) {
  if (data != nullptr) {
    free(data);
  }
}

bool HasAttr(v8::Local<v8::Object> object, const std::string &attribute) {
  return Nan::Has(object, Nan::New(attribute).ToLocalChecked()).FromJust();
}
bool HasAttr(Nan::MaybeLocal<v8::Object> object, const std::string &attribute) {
  return HasAttr(object.ToLocalChecked(), attribute);
}

Nan::MaybeLocal<v8::Value> GetAttr(v8::Local<v8::Object> object, const std::string &attribute) {
  return Nan::Get(object, Nan::New(attribute).ToLocalChecked());
}
Nan::MaybeLocal<v8::Value> GetAttr(Nan::MaybeLocal<v8::Object> object, const std::string &attribute) {
  return GetAttr(object.ToLocalChecked(), attribute);
}

std::string GetAttrStr(v8::Local<v8::Object> object, const std::string &attribute) {
  return *Nan::Utf8String(GetAttr(object, attribute).ToLocalChecked());
}

std::string ToString(v8::Local<v8::Value> string) {
  return *Nan::Utf8String(string);
}

double GetAutorotateAngle(Magick::OrientationType orientationType) {
  switch (orientationType) {
    case Magick::OrientationType::BottomRightOrientation:
      return 90;
    case Magick::OrientationType::RightTopOrientation:
      return 180;
    case Magick::OrientationType::LeftBottomOrientation:
      return 270;
    default:
      return 0;
  }
}
