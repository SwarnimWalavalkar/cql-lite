# A simple database implemented in C from scratch

## Make Instructions

Requirements

```
Tested with:

GNU Make 3.81 and
GNU Make 4.2.1

GCC 9.3.0 and
Apple clang version 13.0.0
```

Build

```
make
```

Run

```
./bin/db ./db
```

Clean

```
make clean
```

## Docker Instructions

Build the docker image

```
docker build . -t cql-lite
```

Run the image

```
docker run -it --rm cql-lite /usr/app/bin/db ./db
```
