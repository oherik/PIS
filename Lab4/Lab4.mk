##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab4
ConfigurationName      :=Debug
WorkspacePath          := "/home/erik/dev/PIS"
ProjectPath            := "/home/erik/dev/PIS/Lab4"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=erik
Date                   :=03/12/15
CodeLitePath           :="/home/erik/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Lab4.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/qtest.c$(ObjectSuffix) $(IntermediateDirectory)/queue.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/qtest.c$(ObjectSuffix): qtest.c $(IntermediateDirectory)/qtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/erik/dev/PIS/Lab4/qtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qtest.c$(DependSuffix): qtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qtest.c$(DependSuffix) -MM "qtest.c"

$(IntermediateDirectory)/qtest.c$(PreprocessSuffix): qtest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qtest.c$(PreprocessSuffix) "qtest.c"

$(IntermediateDirectory)/queue.c$(ObjectSuffix): queue.c $(IntermediateDirectory)/queue.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/erik/dev/PIS/Lab4/queue.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queue.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queue.c$(DependSuffix): queue.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/queue.c$(ObjectSuffix) -MF$(IntermediateDirectory)/queue.c$(DependSuffix) -MM "queue.c"

$(IntermediateDirectory)/queue.c$(PreprocessSuffix): queue.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queue.c$(PreprocessSuffix) "queue.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


