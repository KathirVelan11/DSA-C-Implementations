# File: push-dsa-to-github.ps1

# Navigate to the DSA project folder
Set-Location "$HOME\OneDrive\Desktop\dsa"

# Stage all new/modified files
git add .

# Commit with a default message — change if needed
git commit -m "Update: Added or modified DSA C files"

# Push to GitHub
git push
