#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/final-project-team-yoshi/Arkanoids!/Build/CMakeScripts/ReRunCMake.make
fi

