# Copyright (c) 2011 Bryce Lelbach
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

include(CMakeParseArguments)
include(Phylanx_Include)

phylanx_include(
  Message
  Option
  AddCompileFlag
  AddExecutable
  AddLibraryHeaders
  AddLibrarySources
  AddLinkFlag
  AddPseudoDependencies
  AddPseudoTarget
  AddSourceGroup
  AddTest
  ExportTargets
  ForceOutOfTreeBuild
  IsTarget
  SetupTarget
  ShortenPseudoTarget
)

