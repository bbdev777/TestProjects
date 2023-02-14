#!/bin/bash

set -e

VERSION="1.0.6"

export DOCKER_BUILDKIT=1
docker build -t 10.74.33.15:5000/ant.movements:"${VERSION}" -f ./Docker/Dockerfile .
docker push 10.74.33.15:5000/ant.movements:"${VERSION}"
