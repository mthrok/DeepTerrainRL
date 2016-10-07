# Caffe package for CNN Triplet training
unset(Caffe_FOUND)

message(${Caffe_DIR})
find_path(Caffe_INCLUDE_DIR
  NAMES
  caffe/caffe.hpp
  caffe/common.hpp
  caffe/net.hpp
  caffe/proto/caffe.pb.h
  caffe/util/io.hpp
  caffe/layer.hpp
  HINTS
  ${Caffe_DIR}/include
  /usr/local/include)

find_library(Caffe_LIBS NAMES caffe
  HINTS
  ${Caffe_DIR}/lib
  /usr/local/lib)

if(Caffe_LIBS AND Caffe_INCLUDE_DIR)
  set(Caffe_FOUND 1)
endif()
