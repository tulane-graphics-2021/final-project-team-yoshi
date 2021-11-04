#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build
  make -f /Users/RafaelaHojda/Desktop/Direct-GitHub/module-algorithms-team-yoshi/Asteroids!/Build/CMakeScripts/ReRunCMake.make
fi

