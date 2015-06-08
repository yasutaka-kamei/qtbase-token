begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtestblacklist_p.h"
end_include
begin_include
include|#
directive|include
file|"qtestresult_p.h"
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSysInfo>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*  The file format is simply a grouped listing of keywords  Ungrouped entries at the beginning apply to the whole testcase  Groups define testfunctions or specific test data to ignore.  After the groups come a list of entries (one per line) that define  for which platform/os combination to ignore the test result.  All keys in a single line have to match to blacklist the test.   mac  [testFunction]  linux  windows 64bit  [testfunction2:testData]  msvc   The known keys are listed below: */
DECL|function|keywords
specifier|static
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|keywords
parameter_list|()
block|{
comment|// this list can be extended with new keywords as required
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|set
init|=
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"*"
ifdef|#
directive|ifdef
name|Q_OS_LINUX
operator|<<
literal|"linux"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_OSX
operator|<<
literal|"osx"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"windows"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_IOS
operator|<<
literal|"ios"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_ANDROID
operator|<<
literal|"android"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_QNX
operator|<<
literal|"qnx"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINRT
operator|<<
literal|"winrt"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINCE
operator|<<
literal|"wince"
endif|#
directive|endif
if|#
directive|if
name|QT_POINTER_SIZE
operator|==
literal|8
operator|<<
literal|"64bit"
else|#
directive|else
operator|<<
literal|"32bit"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_CC_GNU
operator|<<
literal|"gcc"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_CC_CLANG
operator|<<
literal|"clang"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_CC_MSVC
operator|<<
literal|"msvc"
ifdef|#
directive|ifdef
name|_MSC_VER
if|#
directive|if
name|_MSC_VER
operator|==
literal|1800
operator|<<
literal|"msvc-2013"
elif|#
directive|elif
name|_MSC_VER
operator|==
literal|1700
operator|<<
literal|"msvc-2012"
elif|#
directive|elif
name|_MSC_VER
operator|==
literal|1600
operator|<<
literal|"msvc-2010"
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_AUTOTEST_EXPORT
operator|<<
literal|"developer-build"
endif|#
directive|endif
decl_stmt|;
name|QCoreApplication
modifier|*
name|app
init|=
name|QCoreApplication
operator|::
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|app
condition|)
block|{
specifier|const
name|QVariant
name|platformName
init|=
name|app
operator|->
name|property
argument_list|(
literal|"platformName"
argument_list|)
decl_stmt|;
if|if
condition|(
name|platformName
operator|.
name|isValid
argument_list|()
condition|)
name|set
operator|<<
name|platformName
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
block|}
return|return
name|set
return|;
block|}
end_function
begin_function
DECL|function|checkCondition
specifier|static
name|bool
name|checkCondition
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|condition
parameter_list|)
block|{
specifier|static
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|matchedConditions
init|=
name|keywords
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|conds
init|=
name|condition
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
name|QByteArray
name|distributionName
init|=
name|QSysInfo
operator|::
name|productType
argument_list|()
operator|.
name|toLower
argument_list|()
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|QByteArray
name|distributionRelease
init|=
name|QSysInfo
operator|::
name|productVersion
argument_list|()
operator|.
name|toLower
argument_list|()
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|distributionName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|matchedConditions
operator|.
name|find
argument_list|(
name|distributionName
argument_list|)
operator|==
name|matchedConditions
operator|.
name|end
argument_list|()
condition|)
name|matchedConditions
operator|.
name|insert
argument_list|(
name|distributionName
argument_list|)
expr_stmt|;
name|matchedConditions
operator|.
name|insert
argument_list|(
name|distributionName
operator|+
literal|"-"
operator|+
name|distributionRelease
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|conds
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|c
init|=
name|conds
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|bool
name|result
init|=
name|c
operator|.
name|startsWith
argument_list|(
literal|'!'
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
condition|)
name|c
operator|=
name|c
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|result
operator|^=
name|matchedConditions
operator|.
name|contains
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|ignoreAll
specifier|static
name|bool
name|ignoreAll
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ignoredTests
specifier|static
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
modifier|*
name|ignoredTests
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|gpuFeatures
specifier|static
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
modifier|*
name|gpuFeatures
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function_decl
DECL|member|qgpu_features_ptr
name|Q_TESTLIB_EXPORT
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
modifier|*
function_decl|(
modifier|*
name|qgpu_features_ptr
function_decl|)
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|=
literal|0
function_decl|;
end_function_decl
begin_function
DECL|function|isGPUTestBlacklisted
specifier|static
name|bool
name|isGPUTestBlacklisted
parameter_list|(
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
block|{
specifier|const
name|QByteArray
name|disableKey
init|=
name|QByteArrayLiteral
argument_list|(
literal|"disable_"
argument_list|)
operator|+
name|QByteArray
argument_list|(
name|slot
argument_list|)
decl_stmt|;
if|if
condition|(
name|gpuFeatures
operator|->
name|find
argument_list|(
name|disableKey
argument_list|)
operator|!=
name|gpuFeatures
operator|->
name|end
argument_list|()
condition|)
block|{
specifier|const
name|QByteArray
name|msg
init|=
name|QByteArrayLiteral
argument_list|(
literal|"Skipped due to GPU blacklist: "
argument_list|)
operator|+
name|disableKey
decl_stmt|;
name|QTest
operator|::
name|qSkip
argument_list|(
name|msg
operator|.
name|constData
argument_list|()
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_namespace
DECL|namespace|QTestPrivate
namespace|namespace
name|QTestPrivate
block|{
DECL|function|parseBlackList
name|void
name|parseBlackList
parameter_list|()
block|{
name|QString
name|filename
init|=
name|QTest
operator|::
name|qFindTestData
argument_list|(
name|QStringLiteral
argument_list|(
literal|"BLACKLIST"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|filename
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QFile
name|ignored
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ignored
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return;
name|QByteArray
name|function
decl_stmt|;
while|while
condition|(
operator|!
name|ignored
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|ignored
operator|.
name|readLine
argument_list|()
operator|.
name|simplified
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|isEmpty
argument_list|()
operator|||
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|'['
argument_list|)
condition|)
block|{
name|function
operator|=
name|line
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|line
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|bool
name|condition
init|=
name|checkCondition
argument_list|(
name|line
argument_list|)
decl_stmt|;
if|if
condition|(
name|condition
condition|)
block|{
if|if
condition|(
operator|!
name|function
operator|.
name|size
argument_list|()
condition|)
block|{
name|ignoreAll
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|ignoredTests
condition|)
name|ignoredTests
operator|=
operator|new
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
expr_stmt|;
name|ignoredTests
operator|->
name|insert
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
DECL|function|parseGpuBlackList
name|void
name|parseGpuBlackList
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qgpu_features_ptr
condition|)
return|return;
name|QString
name|filename
init|=
name|QTest
operator|::
name|qFindTestData
argument_list|(
name|QStringLiteral
argument_list|(
literal|"GPU_BLACKLIST"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|filename
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
operator|!
name|gpuFeatures
condition|)
name|gpuFeatures
operator|=
name|qgpu_features_ptr
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
DECL|function|checkBlackLists
name|void
name|checkBlackLists
parameter_list|(
specifier|const
name|char
modifier|*
name|slot
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
name|bool
name|ignore
init|=
name|ignoreAll
decl_stmt|;
if|if
condition|(
operator|!
name|ignore
operator|&&
name|ignoredTests
condition|)
block|{
name|QByteArray
name|s
init|=
name|slot
decl_stmt|;
name|ignore
operator|=
operator|(
name|ignoredTests
operator|->
name|find
argument_list|(
name|s
argument_list|)
operator|!=
name|ignoredTests
operator|->
name|end
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|ignore
operator|&&
name|data
condition|)
block|{
name|s
operator|+=
literal|':'
expr_stmt|;
name|s
operator|+=
name|data
expr_stmt|;
name|ignore
operator|=
operator|(
name|ignoredTests
operator|->
name|find
argument_list|(
name|s
argument_list|)
operator|!=
name|ignoredTests
operator|->
name|end
argument_list|()
operator|)
expr_stmt|;
block|}
block|}
name|QTestResult
operator|::
name|setBlacklistCurrentTest
argument_list|(
name|ignore
argument_list|)
expr_stmt|;
comment|// Tests blacklisted in GPU_BLACKLIST are to be skipped. Just ignoring the result is
comment|// not sufficient since these are expected to crash or behave in undefined ways.
if|if
condition|(
operator|!
name|ignore
operator|&&
name|gpuFeatures
condition|)
block|{
name|QByteArray
name|s_gpu
init|=
name|slot
decl_stmt|;
name|ignore
operator|=
name|isGPUTestBlacklisted
argument_list|(
name|s_gpu
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ignore
operator|&&
name|data
condition|)
block|{
name|s_gpu
operator|+=
literal|':'
expr_stmt|;
name|s_gpu
operator|+=
name|data
expr_stmt|;
name|isGPUTestBlacklisted
argument_list|(
name|s_gpu
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
