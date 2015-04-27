# M. Bomben
# Mon Apr 27 11:56:23 CEST 2015
# howto add a git repo to github
echo "# tools" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/mbomben/tools.git
git push -u origin master
