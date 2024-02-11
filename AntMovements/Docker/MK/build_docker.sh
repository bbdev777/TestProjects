#!/bin/bash

set -e

VERSION="1.0.7"

export DOCKER_BUILDKIT=1

docker build --no-cache --progress=plain  -t 10.74.33.15:5000/ant.movements:"${VERSION}" -f ./Dockerfile ../../

