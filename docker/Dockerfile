# Reasoning pipeline: Ollama server + Python analysis in one image.
# Build from the repository root:  docker build -f docker/Dockerfile -t reasoning-pipeline .
FROM ollama/ollama:latest

ENV DEBIAN_FRONTEND=noninteractive \
    OLLAMA_HOST=0.0.0.0:11434 \
    OLLAMA_HOST_URL=http://127.0.0.1:11434 \
    OLLAMA_MAX_LOADED_MODELS=1 \
    MPLBACKEND=Agg

RUN apt-get update \
 && apt-get install -y --no-install-recommends python3 python3-requests python3-matplotlib python3-numpy g++ \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY scripts/ scripts/
COPY data/requirements_units.jsonl data/
COPY docker/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh && mkdir -p results generated_code/ollama

# Model weights live in /root/.ollama; results and generated code are written to
# /app/results and /app/generated_code. Mount all three to keep them.
VOLUME ["/root/.ollama", "/app/results", "/app/generated_code"]

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD []
