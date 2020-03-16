# See README.txt.

.PHONY: all write_proto list_people clean

all: write_proto list_people 

clean:
	rm -f proto_main 

protoc_middleman: interface/addressbook.proto
	protoc --cpp_out=. interface/addressbook.proto
	@touch protoc_middleman

write_proto: src/proto_main.cpp protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ src/proto_main.cpp src/addressbook.pb.cc -o write_proto `pkg-config --cflags --libs protobuf`

list_people: src/list_people.cpp protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ src/list_people.cpp src/addressbook.pb.cc -o list_people `pkg-config --cflags --libs protobuf`
