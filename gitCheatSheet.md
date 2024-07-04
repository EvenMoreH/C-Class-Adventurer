<!-- Display all changed files in working directory -->
git status

<!-- Add all current changes to the next commit -->
git add .

<!-- Commit added (staged) changes with a comment -->
git commit -m " "

<!-- Push last commit to GitHub repository -->
git push origin main

<!-- Pull all files form GitHub repository to local directory -->
git pull origin main

<!-- Reset your HEAD pointer to a previous commit & preserve all changes as unstaged changes.
Replace <commit> (including brackets) with commit id you want to revert to -->
git reset --soft <commit>  <!-- example: 'git reset --soft 52e7420' -->

<!-- Create and switch to a new branch in one command: -->
git checkout -b <!-- branchName -->

<!-- List all branches in the repository -->
git branch

<!-- Once you’ve completed work on a branch, you might want to merge it back into the main branch.
First, switch to the branch you want to merge into (e.g., main), then use the git merge command -->
1. git checkout main
2. git merge new-feature

<!-- Once a branch is no longer needed, you can delete it using -->
git branch -d <!-- branchName -->

--------------------------------------------------

# Branching Workflow Examples
## Feature Branch Workflow
### 1. Create a feature branch:
    git checkout -b feature-xyz
### 2. Work on the feature:
<!-- edit some files, develop the feature -->
    git add .
    git commit -m "Add feature XYZ"
### 3. Merge the feature branch back to main:
    git checkout main
    git merge feature-xyz
### 4. Delete the feature branch:
    git branch -d feature-xyz