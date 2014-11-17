begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKEEVALUATOR_H
end_ifndef
begin_define
DECL|macro|QMAKEEVALUATOR_H
define|#
directive|define
name|QMAKEEVALUATOR_H
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PROEVALUATOR_FULL
argument_list|)
operator|&&
name|defined
argument_list|(
name|PROEVALUATOR_THREAD_SAFE
argument_list|)
end_if
begin_error
error|#
directive|error
error|PROEVALUATOR_FULL is incompatible with PROEVALUATOR_THREAD_SAFE due to cache() implementation
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qmakeparser.h"
end_include
begin_include
include|#
directive|include
file|"ioutils.h"
end_include
begin_include
include|#
directive|include
file|<qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qlinkedlist.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qshareddata.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_include
include|#
directive|include
file|<qprocess.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|PROEVALUATOR_THREAD_SAFE
end_ifdef
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMakeGlobals
name|class
name|QMakeGlobals
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMAKE_EXPORT
name|QMakeHandler
range|:
name|public
name|QMakeParserHandler
block|{
name|public
operator|:
expr|enum
block|{
name|SourceEvaluator
operator|=
literal|0x10
block|,
name|EvalWarnLanguage
operator|=
name|SourceEvaluator
operator||
name|WarningMessage
operator||
name|WarnLanguage
block|,
name|EvalWarnDeprecated
operator|=
name|SourceEvaluator
operator||
name|WarningMessage
operator||
name|WarnDeprecated
block|,
name|EvalError
operator|=
name|ErrorMessage
operator||
name|SourceEvaluator
block|}
block|;
comment|// error(), warning() and message() from .pro file
name|virtual
name|void
name|fileMessage
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
operator|=
literal|0
block|;      enum
name|EvalFileType
block|{
name|EvalProjectFile
block|,
name|EvalIncludeFile
block|,
name|EvalConfigFile
block|,
name|EvalFeatureFile
block|,
name|EvalAuxFile
block|}
block|;
name|virtual
name|void
name|aboutToEval
argument_list|(
argument|ProFile *parent
argument_list|,
argument|ProFile *proFile
argument_list|,
argument|EvalFileType type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|doneWithEval
argument_list|(
name|ProFile
operator|*
name|parent
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QString
DECL|typedef|QMakeFeatureKey
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
name|QString
operator|>
name|QMakeFeatureKey
expr_stmt|;
end_typedef
begin_comment
DECL|typedef|QString
DECL|typedef|QMakeFeatureKey
comment|// key, parent
end_comment
begin_typedef
DECL|typedef|QMakeFeatureKey
DECL|typedef|QMakeFeatureHash
typedef|typedef
name|QHash
operator|<
name|QMakeFeatureKey
operator|,
name|QString
operator|>
name|QMakeFeatureHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QMAKE_EXPORT
name|QMakeFeatureRoots
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QMakeFeatureRoots
argument_list|(
specifier|const
name|QStringList
operator|&
name|_paths
argument_list|)
operator|:
name|paths
argument_list|(
argument|_paths
argument_list|)
block|{}
specifier|const
name|QStringList
name|paths
block|;
name|mutable
name|QMakeFeatureHash
name|cache
block|;
ifdef|#
directive|ifdef
name|PROEVALUATOR_THREAD_SAFE
name|mutable
name|QMutex
name|mutex
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// We use a QLinkedList based stack instead of a QVector based one (QStack), so that
end_comment
begin_comment
comment|// the addresses of value maps stay constant. The qmake generators rely on that.
end_comment
begin_decl_stmt
name|class
name|QMAKE_EXPORT
name|ProValueMapStack
range|:
name|public
name|QLinkedList
operator|<
name|ProValueMap
operator|>
block|{
name|public
operator|:
specifier|inline
name|void
name|push
argument_list|(
argument|const ProValueMap&t
argument_list|)
block|{
name|append
argument_list|(
name|t
argument_list|)
block|; }
specifier|inline
name|ProValueMap
name|pop
argument_list|()
block|{
return|return
name|takeLast
argument_list|()
return|;
block|}
name|ProValueMap
operator|&
name|top
argument_list|()
block|{
return|return
name|last
argument_list|()
return|;
block|}
specifier|const
name|ProValueMap
operator|&
name|top
argument_list|()
specifier|const
block|{
return|return
name|last
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|QMAKE_EXPORT
name|QMakeEvaluator
block|{
name|public
operator|:
expr|enum
name|LoadFlag
block|{
name|LoadProOnly
operator|=
literal|0
block|,
name|LoadPreFiles
operator|=
literal|1
block|,
name|LoadPostFiles
operator|=
literal|2
block|,
name|LoadAll
operator|=
name|LoadPreFiles
operator||
name|LoadPostFiles
block|,
name|LoadSilent
operator|=
literal|0x10
block|,
name|LoadHidden
operator|=
literal|0x20
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|LoadFlags
argument_list|,
argument|LoadFlag
argument_list|)
specifier|static
name|void
name|initStatics
argument_list|()
block|;
specifier|static
name|void
name|initFunctionStatics
argument_list|()
block|;
name|QMakeEvaluator
argument_list|(
name|QMakeGlobals
operator|*
name|option
argument_list|,
name|QMakeParser
operator|*
name|parser
argument_list|,
name|QMakeVfs
operator|*
name|vfs
argument_list|,
name|QMakeHandler
operator|*
name|handler
argument_list|)
block|;
operator|~
name|QMakeEvaluator
argument_list|()
block|;
name|void
name|setExtraVars
argument_list|(
argument|const ProValueMap&extraVars
argument_list|)
block|{
name|m_extraVars
operator|=
name|extraVars
block|; }
name|void
name|setExtraConfigs
argument_list|(
argument|const ProStringList&extraConfigs
argument_list|)
block|{
name|m_extraConfigs
operator|=
name|extraConfigs
block|; }
name|void
name|setOutputDir
argument_list|(
argument|const QString&outputDir
argument_list|)
block|{
name|m_outputDir
operator|=
name|outputDir
block|; }
name|ProStringList
name|values
argument_list|(
argument|const ProKey&variableName
argument_list|)
specifier|const
block|;
name|ProStringList
operator|&
name|valuesRef
argument_list|(
specifier|const
name|ProKey
operator|&
name|variableName
argument_list|)
block|;
name|ProString
name|first
argument_list|(
argument|const ProKey&variableName
argument_list|)
specifier|const
block|;
name|ProString
name|propertyValue
argument_list|(
argument|const ProKey&val
argument_list|)
specifier|const
block|;
name|ProString
name|dirSep
argument_list|()
specifier|const
block|{
return|return
name|m_dirSep
return|;
block|}
name|bool
name|isHostBuild
argument_list|()
specifier|const
block|{
return|return
name|m_hostBuild
return|;
block|}
expr|enum
name|VisitReturn
block|{
name|ReturnFalse
block|,
name|ReturnTrue
block|,
name|ReturnError
block|,
name|ReturnBreak
block|,
name|ReturnNext
block|,
name|ReturnReturn
block|}
block|;
specifier|static
name|ALWAYS_INLINE
name|VisitReturn
name|returnBool
argument_list|(
argument|bool b
argument_list|)
block|{
return|return
name|b
operator|?
name|ReturnTrue
operator|:
name|ReturnFalse
return|;
block|}
specifier|static
name|ALWAYS_INLINE
name|uint
name|getBlockLen
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|ProString
name|getStr
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|ProKey
name|getHashStr
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|void
name|evaluateExpression
argument_list|(
argument|const ushort *&tokPtr
argument_list|,
argument|ProStringList *ret
argument_list|,
argument|bool joined
argument_list|)
block|;
specifier|static
name|ALWAYS_INLINE
name|void
name|skipStr
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
specifier|static
name|ALWAYS_INLINE
name|void
name|skipHashStr
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|void
name|skipExpression
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|void
name|loadDefaults
argument_list|()
block|;
name|bool
name|prepareProject
argument_list|(
specifier|const
name|QString
operator|&
name|inDir
argument_list|)
block|;
name|bool
name|loadSpecInternal
argument_list|()
block|;
name|bool
name|loadSpec
argument_list|()
block|;
name|void
name|initFrom
argument_list|(
specifier|const
name|QMakeEvaluator
operator|*
name|other
argument_list|)
block|;
name|void
name|setupProject
argument_list|()
block|;
name|void
name|evaluateCommand
argument_list|(
specifier|const
name|QString
operator|&
name|cmds
argument_list|,
specifier|const
name|QString
operator|&
name|where
argument_list|)
block|;
name|void
name|applyExtraConfigs
argument_list|()
block|;
name|VisitReturn
name|visitProFile
argument_list|(
argument|ProFile *pro
argument_list|,
argument|QMakeHandler::EvalFileType type
argument_list|,
argument|LoadFlags flags
argument_list|)
block|;
name|VisitReturn
name|visitProBlock
argument_list|(
name|ProFile
operator|*
name|pro
argument_list|,
specifier|const
name|ushort
operator|*
name|tokPtr
argument_list|)
block|;
name|VisitReturn
name|visitProBlock
argument_list|(
specifier|const
name|ushort
operator|*
name|tokPtr
argument_list|)
block|;
name|VisitReturn
name|visitProLoop
argument_list|(
specifier|const
name|ProKey
operator|&
name|variable
argument_list|,
specifier|const
name|ushort
operator|*
name|exprPtr
argument_list|,
specifier|const
name|ushort
operator|*
name|tokPtr
argument_list|)
block|;
name|void
name|visitProFunctionDef
argument_list|(
argument|ushort tok
argument_list|,
argument|const ProKey&name
argument_list|,
argument|const ushort *tokPtr
argument_list|)
block|;
name|void
name|visitProVariable
argument_list|(
argument|ushort tok
argument_list|,
argument|const ProStringList&curr
argument_list|,
argument|const ushort *&tokPtr
argument_list|)
block|;
name|ALWAYS_INLINE
specifier|const
name|ProKey
operator|&
name|map
argument_list|(
argument|const ProString&var
argument_list|)
block|{
return|return
name|map
argument_list|(
name|var
operator|.
name|toKey
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|ProKey
operator|&
name|map
argument_list|(
specifier|const
name|ProKey
operator|&
name|var
argument_list|)
block|;
name|ProValueMap
operator|*
name|findValues
argument_list|(
specifier|const
name|ProKey
operator|&
name|variableName
argument_list|,
name|ProValueMap
operator|::
name|Iterator
operator|*
name|it
argument_list|)
block|;
name|void
name|setTemplate
argument_list|()
block|;
name|ProStringList
name|split_value_list
argument_list|(
specifier|const
name|QString
operator|&
name|vals
argument_list|,
specifier|const
name|ProFile
operator|*
name|source
operator|=
literal|0
argument_list|)
block|;
name|ProStringList
name|expandVariableReferences
argument_list|(
argument|const ProString&value
argument_list|,
argument|int *pos =
literal|0
argument_list|,
argument|bool joined = false
argument_list|)
block|;
name|ProStringList
name|expandVariableReferences
argument_list|(
argument|const ushort *&tokPtr
argument_list|,
argument|int sizeHint =
literal|0
argument_list|,
argument|bool joined = false
argument_list|)
block|;
name|QString
name|currentFileName
argument_list|()
specifier|const
block|;
name|QString
name|currentDirectory
argument_list|()
specifier|const
block|;
name|ProFile
operator|*
name|currentProFile
argument_list|()
specifier|const
block|;
name|QString
name|resolvePath
argument_list|(
argument|const QString&fileName
argument_list|)
specifier|const
block|{
return|return
name|QMakeInternal
operator|::
name|IoUtils
operator|::
name|resolvePath
argument_list|(
name|currentDirectory
argument_list|()
argument_list|,
name|fileName
argument_list|)
return|;
block|}
name|VisitReturn
name|evaluateFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|QMakeHandler::EvalFileType type
argument_list|,
argument|LoadFlags flags
argument_list|)
block|;
name|VisitReturn
name|evaluateFileChecked
argument_list|(
argument|const QString&fileName
argument_list|,
argument|QMakeHandler::EvalFileType type
argument_list|,
argument|LoadFlags flags
argument_list|)
block|;
name|VisitReturn
name|evaluateFeatureFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|bool silent = false
argument_list|)
block|;
name|VisitReturn
name|evaluateFileInto
argument_list|(
argument|const QString&fileName
argument_list|,
argument|ProValueMap *values
argument_list|,
comment|// output-only
argument|LoadFlags flags
argument_list|)
block|;
name|VisitReturn
name|evaluateConfigFeatures
argument_list|()
block|;
name|void
name|message
argument_list|(
argument|int type
argument_list|,
argument|const QString&msg
argument_list|)
specifier|const
block|;
name|void
name|evalError
argument_list|(
argument|const QString&msg
argument_list|)
specifier|const
block|{
name|message
argument_list|(
name|QMakeHandler
operator|::
name|EvalError
argument_list|,
name|msg
argument_list|)
block|; }
name|void
name|languageWarning
argument_list|(
argument|const QString&msg
argument_list|)
specifier|const
block|{
name|message
argument_list|(
name|QMakeHandler
operator|::
name|EvalWarnLanguage
argument_list|,
name|msg
argument_list|)
block|; }
name|void
name|deprecationWarning
argument_list|(
argument|const QString&msg
argument_list|)
specifier|const
block|{
name|message
argument_list|(
name|QMakeHandler
operator|::
name|EvalWarnDeprecated
argument_list|,
name|msg
argument_list|)
block|; }
name|QList
operator|<
name|ProStringList
operator|>
name|prepareFunctionArgs
argument_list|(
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|ProStringList
name|evaluateFunction
argument_list|(
specifier|const
name|ProFunctionDef
operator|&
name|func
argument_list|,
specifier|const
name|QList
operator|<
name|ProStringList
operator|>
operator|&
name|argumentsList
argument_list|,
name|VisitReturn
operator|*
name|ok
argument_list|)
block|;
name|VisitReturn
name|evaluateBoolFunction
argument_list|(
specifier|const
name|ProFunctionDef
operator|&
name|func
argument_list|,
specifier|const
name|QList
operator|<
name|ProStringList
operator|>
operator|&
name|argumentsList
argument_list|,
specifier|const
name|ProString
operator|&
name|function
argument_list|)
block|;
name|ProStringList
name|evaluateExpandFunction
argument_list|(
specifier|const
name|ProKey
operator|&
name|function
argument_list|,
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|VisitReturn
name|evaluateConditionalFunction
argument_list|(
specifier|const
name|ProKey
operator|&
name|function
argument_list|,
specifier|const
name|ushort
operator|*
operator|&
name|tokPtr
argument_list|)
block|;
name|ProStringList
name|evaluateBuiltinExpand
argument_list|(
argument|int func_t
argument_list|,
argument|const ProKey&function
argument_list|,
argument|const ProStringList&args
argument_list|)
block|;
name|VisitReturn
name|evaluateBuiltinConditional
argument_list|(
argument|int func_t
argument_list|,
argument|const ProKey&function
argument_list|,
argument|const ProStringList&args
argument_list|)
block|;
name|bool
name|evaluateConditional
argument_list|(
argument|const QString&cond
argument_list|,
argument|const QString&where
argument_list|,
argument|int line = -
literal|1
argument_list|)
block|;
ifdef|#
directive|ifdef
name|PROEVALUATOR_FULL
name|void
name|checkRequirements
argument_list|(
specifier|const
name|ProStringList
operator|&
name|deps
argument_list|)
block|;
endif|#
directive|endif
name|void
name|updateMkspecPaths
argument_list|()
block|;
name|void
name|updateFeaturePaths
argument_list|()
block|;
name|bool
name|isActiveConfig
argument_list|(
argument|const QString&config
argument_list|,
argument|bool regex = false
argument_list|)
block|;
name|void
name|populateDeps
argument_list|(
argument|const ProStringList&deps
argument_list|,
argument|const ProString&prefix
argument_list|,
argument|const ProStringList&suffixes
argument_list|,
argument|const ProString&priosfx
argument_list|,
argument|QHash<ProKey
argument_list|,
argument|QSet<ProKey>>&dependencies
argument_list|,
argument|ProValueMap&dependees
argument_list|,
argument|QMultiMap<int
argument_list|,
argument|ProString>&rootSet
argument_list|)
specifier|const
block|;
name|VisitReturn
name|writeFile
argument_list|(
argument|const QString&ctx
argument_list|,
argument|const QString&fn
argument_list|,
argument|QIODevice::OpenMode mode
argument_list|,
argument|const QString&contents
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|void
name|runProcess
argument_list|(
argument|QProcess *proc
argument_list|,
argument|const QString&command
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|QByteArray
name|getCommandOutput
argument_list|(
argument|const QString&args
argument_list|)
specifier|const
block|;
specifier|static
name|void
name|removeEach
argument_list|(
name|ProStringList
operator|*
name|varlist
argument_list|,
specifier|const
name|ProStringList
operator|&
name|value
argument_list|)
block|;
name|QMakeEvaluator
operator|*
name|m_caller
block|;
ifdef|#
directive|ifdef
name|PROEVALUATOR_CUMULATIVE
name|bool
name|m_cumulative
block|;
name|int
name|m_skipLevel
block|;
else|#
directive|else
block|enum
block|{
name|m_cumulative
operator|=
literal|0
block|}
block|;     enum
block|{
name|m_skipLevel
operator|=
literal|0
block|}
block|;
endif|#
directive|endif
specifier|static
name|QString
name|quoteValue
argument_list|(
specifier|const
name|ProString
operator|&
name|val
argument_list|)
block|;
ifdef|#
directive|ifdef
name|PROEVALUATOR_DEBUG
name|void
name|debugMsgInternal
argument_list|(
argument|int level
argument_list|,
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
specifier|const
block|;
name|void
name|traceMsgInternal
argument_list|(
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
specifier|const
block|;
specifier|static
name|QString
name|formatValue
argument_list|(
argument|const ProString&val
argument_list|,
argument|bool forceQuote = false
argument_list|)
block|;
specifier|static
name|QString
name|formatValueList
argument_list|(
argument|const ProStringList&vals
argument_list|,
argument|bool commas = false
argument_list|)
block|;
specifier|static
name|QString
name|formatValueListList
argument_list|(
specifier|const
name|QList
operator|<
name|ProStringList
operator|>
operator|&
name|vals
argument_list|)
block|;
specifier|const
name|int
name|m_debugLevel
block|;
else|#
directive|else
name|ALWAYS_INLINE
name|void
name|debugMsgInternal
argument_list|(
argument|int
argument_list|,
argument|const char *
argument_list|,
argument|...
argument_list|)
specifier|const
block|{}
name|ALWAYS_INLINE
name|void
name|traceMsgInternal
argument_list|(
argument|const char *
argument_list|,
argument|...
argument_list|)
specifier|const
block|{}
expr|enum
block|{
name|m_debugLevel
operator|=
literal|0
block|}
block|;
endif|#
directive|endif
block|struct
name|Location
block|{
name|Location
argument_list|()
operator|:
name|pro
argument_list|(
literal|0
argument_list|)
block|,
name|line
argument_list|(
literal|0
argument_list|)
block|{}
name|Location
argument_list|(
argument|ProFile *_pro
argument_list|,
argument|ushort _line
argument_list|)
operator|:
name|pro
argument_list|(
name|_pro
argument_list|)
block|,
name|line
argument_list|(
argument|_line
argument_list|)
block|{}
name|void
name|clear
argument_list|()
block|{
name|pro
operator|=
literal|0
block|;
name|line
operator|=
literal|0
block|; }
name|ProFile
operator|*
name|pro
block|;
name|ushort
name|line
block|;     }
block|;
name|Location
name|m_current
block|;
comment|// Currently evaluated location
name|QStack
operator|<
name|Location
operator|>
name|m_locationStack
block|;
comment|// All execution location changes
name|QStack
operator|<
name|ProFile
operator|*
operator|>
name|m_profileStack
block|;
comment|// Includes only
name|ProValueMap
name|m_extraVars
block|;
name|ProStringList
name|m_extraConfigs
block|;
name|QString
name|m_outputDir
block|;
name|int
name|m_listCount
block|;
name|bool
name|m_valuemapInited
block|;
name|bool
name|m_hostBuild
block|;
name|QString
name|m_qmakespec
block|;
name|QString
name|m_qmakespecName
block|;
name|QString
name|m_superfile
block|;
name|QString
name|m_conffile
block|;
name|QString
name|m_cachefile
block|;
name|QString
name|m_stashfile
block|;
name|QString
name|m_sourceRoot
block|;
name|QString
name|m_buildRoot
block|;
name|QStringList
name|m_qmakepath
block|;
name|QStringList
name|m_qmakefeatures
block|;
name|QStringList
name|m_mkspecPaths
block|;
name|QExplicitlySharedDataPointer
operator|<
name|QMakeFeatureRoots
operator|>
name|m_featureRoots
block|;
name|ProString
name|m_dirSep
block|;
name|ProFunctionDefs
name|m_functionDefs
block|;
name|ProStringList
name|m_returnValue
block|;
name|ProValueMapStack
name|m_valuemapStack
block|;
comment|// VariableName must be us-ascii, the content however can be non-us-ascii.
name|QString
name|m_tmp1
block|,
name|m_tmp2
block|,
name|m_tmp3
block|,
name|m_tmp
index|[
literal|2
index|]
block|;
comment|// Temporaries for efficient toQString
name|mutable
name|QString
name|m_mtmp
block|;
name|QMakeGlobals
operator|*
name|m_option
block|;
name|QMakeParser
operator|*
name|m_parser
block|;
name|QMakeHandler
operator|*
name|m_handler
block|;
name|QMakeVfs
operator|*
name|m_vfs
block|; }
block|;
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QMakeEvaluator::LoadFlags
argument_list|)
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMAKEEVALUATOR_H
end_comment
end_unit
