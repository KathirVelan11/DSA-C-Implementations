#!/bin/bash

# This script is placed inside the "dsa" folder

# Initialize git (only if not already)
git init

# Rename default branch to main
git branch -M main

# Set GitHub remote (remove existing one if needed)
git remote remove origin 2>/dev/null
git remote add origin https://github.com/KathirVelan11/DSA-C-Implementations.git

# Add all files and folders recursively
git add .

# Commit with a generic message
git commit -m "Initial commit of all DSA folders and C files"

# Push to GitHub
git push -u origin main
