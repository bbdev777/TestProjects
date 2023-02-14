FROM ubuntu:20.04 AS build

ENV DEBIAN_FRONTEND="noninteractive"
ENV TZ="UTC"

RUN apt update \
	&& apt -y install \
		build-essential \
		cmake \
		curl \
		git \
		ninja-build \
		pkg-config \
	&& rm -rf /var/lib/apt/lists/*


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


#VOLUME ["/data"]
FROM ubuntu:20.04 AS Release
COPY --from=build /Release/AntMovements /AntMovements
