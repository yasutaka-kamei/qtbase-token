begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PROJECT_H
end_ifndef
begin_define
DECL|macro|PROJECT_H
define|#
directive|define
name|PROJECT_H
end_define
begin_include
include|#
directive|include
file|<qmakeevaluator.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMakeProject
range|:
name|private
name|QMakeEvaluator
block|{
name|QString
name|m_projectFile
block|;
name|public
operator|:
name|QMakeProject
argument_list|()
block|;
name|QMakeProject
argument_list|(
name|QMakeProject
operator|*
name|p
argument_list|)
block|;
name|bool
name|read
argument_list|(
argument|const QString&project
argument_list|,
argument|LoadFlags what = LoadAll
argument_list|)
block|;
name|QString
name|projectFile
argument_list|()
specifier|const
block|{
return|return
name|m_projectFile
return|;
block|}
name|QString
name|buildRoot
argument_list|()
specifier|const
block|{
return|return
name|m_buildRoot
return|;
block|}
name|QString
name|confFile
argument_list|()
specifier|const
block|{
return|return
name|m_conffile
return|;
block|}
name|QString
name|cacheFile
argument_list|()
specifier|const
block|{
return|return
name|m_cachefile
return|;
block|}
name|QString
name|specDir
argument_list|()
specifier|const
block|{
return|return
name|m_qmakespec
return|;
block|}
name|ProString
name|expand
argument_list|(
argument|const QString&v
argument_list|,
argument|const QString&file
argument_list|,
argument|int line
argument_list|)
block|;
name|QStringList
name|expand
argument_list|(
specifier|const
name|ProKey
operator|&
name|func
argument_list|,
specifier|const
name|QList
operator|<
name|ProStringList
operator|>
operator|&
name|args
argument_list|)
block|;
name|bool
name|test
argument_list|(
argument|const QString&v
argument_list|,
argument|const QString&file
argument_list|,
argument|int line
argument_list|)
block|{
name|m_current
operator|.
name|clear
argument_list|()
block|;
return|return
name|evaluateConditional
argument_list|(
name|v
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|bool
name|test
argument_list|(
specifier|const
name|ProKey
operator|&
name|func
argument_list|,
specifier|const
name|QList
operator|<
name|ProStringList
operator|>
operator|&
name|args
argument_list|)
block|;
name|bool
name|isSet
argument_list|(
argument|const ProKey&v
argument_list|)
specifier|const
block|{
return|return
name|m_valuemapStack
operator|.
name|first
argument_list|()
operator|.
name|contains
argument_list|(
name|v
argument_list|)
return|;
block|}
name|bool
name|isEmpty
argument_list|(
argument|const ProKey&v
argument_list|)
specifier|const
block|;
name|ProStringList
operator|&
name|values
argument_list|(
argument|const ProKey&v
argument_list|)
block|{
return|return
name|valuesRef
argument_list|(
name|v
argument_list|)
return|;
block|}
name|int
name|intValue
argument_list|(
argument|const ProKey&v
argument_list|,
argument|int defaultValue =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|ProValueMap
operator|&
name|variables
argument_list|()
specifier|const
block|{
return|return
name|m_valuemapStack
operator|.
name|first
argument_list|()
return|;
block|}
name|ProValueMap
operator|&
name|variables
argument_list|()
block|{
return|return
name|m_valuemapStack
operator|.
name|first
argument_list|()
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
block|;
name|using
name|QMakeEvaluator
operator|::
name|LoadFlags
block|;
name|using
name|QMakeEvaluator
operator|::
name|VisitReturn
block|;
name|using
name|QMakeEvaluator
operator|::
name|setExtraVars
block|;
name|using
name|QMakeEvaluator
operator|::
name|setExtraConfigs
block|;
name|using
name|QMakeEvaluator
operator|::
name|loadSpec
block|;
name|using
name|QMakeEvaluator
operator|::
name|evaluateFeatureFile
block|;
name|using
name|QMakeEvaluator
operator|::
name|evaluateConfigFeatures
block|;
name|using
name|QMakeEvaluator
operator|::
name|evaluateExpression
block|;
name|using
name|QMakeEvaluator
operator|::
name|values
block|;
name|using
name|QMakeEvaluator
operator|::
name|first
block|;
name|using
name|QMakeEvaluator
operator|::
name|isActiveConfig
block|;
name|using
name|QMakeEvaluator
operator|::
name|isHostBuild
block|;
name|using
name|QMakeEvaluator
operator|::
name|dirSep
block|;
name|private
operator|:
specifier|static
name|bool
name|boolRet
argument_list|(
argument|VisitReturn vr
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|intValue
specifier|inline
name|int
name|QMakeProject
operator|::
name|intValue
argument_list|(
argument|const ProKey&v
argument_list|,
argument|int defaultValue
argument_list|)
specifier|const
block|{
specifier|const
name|ProString
operator|&
name|str
operator|=
name|first
argument_list|(
name|v
argument_list|)
block|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|i
init|=
name|str
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
return|return
name|i
return|;
block|}
end_expr_stmt
begin_return
return|return
name|defaultValue
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// PROJECT_H
end_comment
end_unit
