FROM 10.74.33.15:5000/ubuntu-20.04-dev-image:1.0.1 AS build

ENV DEBIAN_FRONTEND="noninteractive"
ENV TZ="UTC"

####################################################################################################
# Apps
####################################################################################################

RUN mkdir -p /src/AntMovements
RUN mkdir -p /build-folder
RUN mkdir -p /Release
RUN --mount=type=bind,source=.,target=/src/AntMovements \
    --mount=type=cache,target=/build-folder \
    cd /build-folder \
    && cmake -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        /src/AntMovements \
    && ninja clean \
    && ninja -j4 \
    && cp -r /build-folder/AntMovements /Release/AntMovements


FROM 10.74.33.15:5000/ubuntu-20.04-rel-image:1.0.1 AS Release

COPY --from=build /Release/AntMovements /AntMovements
