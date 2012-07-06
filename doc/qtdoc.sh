#!/bin/bash

asciidoc manual.asciidoc
asciidoc user_guide.asciidoc
asciidoc compiling.asciidoc
qhelpgenerator rapcad.qhp -o rapcad.qch
qcollectiongenerator rapcad.qhcp -o rapcad-docs.qch
