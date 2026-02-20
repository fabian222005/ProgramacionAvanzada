#!/bin/bash

# Fecha actual
DAY=$(date +"%Y-%m-%d")

# Agregar cambios
git add .

# Commit con fecha automática
git commit -m "Update $DAY"

# Push
git push origin master
