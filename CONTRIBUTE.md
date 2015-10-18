To modify / add items to these pages:

- Fork the ESC repository and clone it locally.

        git clone https://github.com/<your-username>/esc15

- Modify a file or add a new one in the directories already present, or create
  a new one directory. Notice that each file needs to:
  - be formatted using markdown
  - have a `.markdown` extension
  - Start with a YAML header like:

        ---
        title: Title of the exercise
        layout: main
        ---

- Modify the document structure `menu` in _config.yml to point
  to your newly introduced file. `name` needs to be the name of
  the directory containing your file. `label` is the name which will
  appear in the menu on the left. For example have a look at what done in
  <https://github.com/infn-esc/esc15/commit/2077e34c113fa9c39a397a33a4c1fbb2014ffa92>

- Push  your changes to Github and do a pull request with your changes.
  You can preview your changes by going to
  `https://<github-username>.github.io/esc15/`.

- Once the pull request is merged, your changes will be visible at:

  <https://infn-esc.github.io/esc15/>

