# Inputs

This folder has the code examples.

`quixbugs` folder contains the QuixBugs dataset version
<https://github.com/jkoppel/QuixBugs/commit/4257f44b0ff1181dedaedee6a447e133219fcebf>
with small modifications by us.
* Python programs have the final comment/documentation multiline strings removed.
  These strings are different between buggy and fixed versions but
  are irrelevant for the bugs themselves.
  Comments are also removed to simplify the text diffs.

`defects4j` folder contains the defects4j dataset <https://github.com/rjust/defects4j/commit/b710dec28986dfe618ef2d4696abecce00d119d9>
with small modifications by us.
* Bugs which touch several files are removed.
* Buggy and fixed version are in the same folder. The buggy version
  has the `.before` extension and the fixed version of the file
  has the `.after` extension.
