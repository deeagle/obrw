#!/bin/bash

set -o errexit
set -o nounset
set -o pipefail

echo "Running CI ..."

echo "Lint markdown ..."
docker run --rm -v "$(pwd):/app" docdee/mdlint -c /app/.markdownlint.yml "*.md"

echo "Lint Shell scripts ..."
shell_linter_version="$(docker run --rm -i koalaman/shellcheck:stable --version)"
echo "Using shellcheck version: ${shell_linter_version}"
shellfiles=$(find . -type f -name "*.sh" -not -path "./vendor/*" -not -path "./tmp/*")
for shellfile in ${shellfiles};
do
  echo "> lint file: $shellfile"
  docker run --rm -i -v "${PWD}:/mnt" koalaman/shellcheck:stable "$shellfile"
done

echo "Run cppcheck ..."
docker run --rm -i cppcheck:local
docker run --rm -i -v ./src:/app:ro cppcheck:local /app

echo "Running CI successfull finished."
