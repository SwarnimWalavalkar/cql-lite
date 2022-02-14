FROM alpine:latest

WORKDIR /usr/app/
COPY . ./

RUN apk update
RUN apk add gcc
RUN apk add make
RUN apk add musl-dev

RUN make

FROM alpine:latest

WORKDIR /usr/app
COPY --from=0 /usr/app ./