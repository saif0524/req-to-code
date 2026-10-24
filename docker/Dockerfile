# Toolchain for the replication package: Python, g++, cppcheck, ESBMC.
# Ollama runs as a separate service (see docker-compose.yml).
# Build from the repository root:  docker build -f docker/Dockerfile -t req-to-code .
FROM ubuntu:24.04

ARG CPPCHECK_VERSION=2.19.0
ARG ESBMC_VERSION=v8.0

ENV DEBIAN_FRONTEND=noninteractive \
    MPLBACKEND=Agg \
    PYTHONUNBUFFERED=1 \
    OLLAMA_HOST_URL=http://ollama:11434

RUN apt-get update \
 && apt-get install -y --no-install-recommends \
      python3 python3-requests python3-numpy python3-matplotlib python3-lxml \
      g++ make cmake git unzip curl ca-certificates \
 && rm -rf /var/lib/apt/lists/*

# cppcheck is built from source because the Ubuntu package is older than the version used in the study.
RUN git clone --depth 1 --branch ${CPPCHECK_VERSION} https://github.com/danmar/cppcheck.git /tmp/cppcheck \
 && cmake -S /tmp/cppcheck -B /tmp/cppcheck/build -DCMAKE_BUILD_TYPE=Release -DFILESDIR=/usr/local/share/Cppcheck \
 && cmake --build /tmp/cppcheck/build -j"$(nproc)" \
 && cmake --install /tmp/cppcheck/build \
 && rm -rf /tmp/cppcheck

RUN curl -fsSL -o /tmp/esbmc.zip \
      https://github.com/esbmc/esbmc/releases/download/${ESBMC_VERSION}/esbmc-linux.zip \
 && unzip -q /tmp/esbmc.zip -d /opt/esbmc \
 && chmod +x /opt/esbmc/bin/esbmc \
 && ln -s /opt/esbmc/bin/esbmc /usr/local/bin/esbmc \
 && rm /tmp/esbmc.zip

WORKDIR /app
COPY scripts/ scripts/
COPY data/ data/
COPY docs/labeling_guideline.md docs/
RUN mkdir -p results

VOLUME ["/app/results"]
CMD ["bash"]
