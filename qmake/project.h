begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QString
name|m_projectDir
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
name|projectDir
argument_list|()
specifier|const
block|{
return|return
name|m_projectDir
return|;
block|}
name|QString
name|sourceRoot
argument_list|()
specifier|const
block|{
return|return
name|m_sourceRoot
operator|.
name|isEmpty
argument_list|()
operator|?
name|m_buildRoot
operator|:
name|m_sourceRoot
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
name|propertyValue
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
begin_comment
comment|/*!  * For variables that are supposed to contain a single int,  * this method returns the numeric value.  * Only the first value of the variable is taken into account.  * The string representation is assumed to look like a C int literal.  */
end_comment
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
argument_list|,
literal|0
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
