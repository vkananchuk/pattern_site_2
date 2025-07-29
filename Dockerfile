FROM ruby:3.4


# Install all required packages
RUN apt-get update \
	&& apt-get install -y --no-install-recommends openjdk-17-jdk wget git gdebi-core \
	    build-essential ocaml libnum-ocaml-dev python3-pip python3-dev nodejs npm \
	    tzdata ca-certificates p11-kit cargo

# Install gumtree
RUN wget https://github.com/GumTreeDiff/gumtree/releases/download/v3.0.0/gumtree-3.0.0.zip \
    && unzip gumtree-3.0.0.zip \
    && cp gumtree-3.0.0/bin/gumtree /usr/bin/gumtree \
    && cp gumtree-3.0.0/lib/gumtree.jar /usr/lib/gumtree.jar

RUN wget https://github.com/tree-sitter/tree-sitter/releases/download/v0.22.6/tree-sitter-linux-x64.gz \
  && gunzip tree-sitter-linux-x64.gz \
  && cp tree-sitter-linux-x64 /usr/bin/tree-sitter \
  && chmod +x /usr/bin/tree-sitter
