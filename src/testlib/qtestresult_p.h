begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTRESULT_P_H
end_ifndef
begin_define
DECL|macro|QTESTRESULT_P_H
define|#
directive|define
name|QTESTRESULT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTestResultPrivate
name|class
name|QTestResultPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTestData
name|class
name|QTestData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_TESTLIB_EXPORT
name|QTestResult
block|{
name|public
label|:
enum|enum
name|TestLocation
block|{
name|NoWhere
init|=
literal|0
block|,
name|DataFunc
init|=
literal|1
block|,
name|InitFunc
init|=
literal|2
block|,
name|Func
init|=
literal|3
block|,
name|CleanupFunc
init|=
literal|4
block|}
enum|;
specifier|static
specifier|const
name|char
modifier|*
name|currentTestObjectName
parameter_list|()
function_decl|;
specifier|static
name|bool
name|currentTestFailed
parameter_list|()
function_decl|;
specifier|static
name|QTestData
modifier|*
name|currentTestData
parameter_list|()
function_decl|;
specifier|static
name|QTestData
modifier|*
name|currentGlobalTestData
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|currentTestFunction
parameter_list|()
function_decl|;
specifier|static
name|TestLocation
name|currentTestLocation
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|currentDataTag
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|currentGlobalDataTag
parameter_list|()
function_decl|;
specifier|static
name|void
name|finishedCurrentTestFunction
parameter_list|()
function_decl|;
specifier|static
name|void
name|reset
parameter_list|()
function_decl|;
specifier|static
name|void
name|addFailure
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|bool
name|compare
parameter_list|(
name|bool
name|success
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|bool
name|compare
parameter_list|(
name|bool
name|success
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|char
modifier|*
name|val1
parameter_list|,
name|char
modifier|*
name|val2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|setCurrentGlobalTestData
parameter_list|(
name|QTestData
modifier|*
name|data
parameter_list|)
function_decl|;
specifier|static
name|void
name|setCurrentTestData
parameter_list|(
name|QTestData
modifier|*
name|data
parameter_list|)
function_decl|;
specifier|static
name|void
name|setCurrentTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
specifier|static
name|void
name|setCurrentTestLocation
parameter_list|(
name|TestLocation
name|loc
parameter_list|)
function_decl|;
specifier|static
name|void
name|setCurrentTestObject
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
specifier|static
name|void
name|addSkip
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|bool
name|expectFail
argument_list|(
specifier|const
name|char
operator|*
name|dataIndex
argument_list|,
specifier|const
name|char
operator|*
name|comment
argument_list|,
name|QTest
operator|::
name|TestFailMode
name|mode
argument_list|,
specifier|const
name|char
operator|*
name|file
argument_list|,
name|int
name|line
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|verify
parameter_list|(
name|bool
name|statement
parameter_list|,
specifier|const
name|char
modifier|*
name|statementStr
parameter_list|,
specifier|const
name|char
modifier|*
name|extraInfo
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|bool
name|testFailed
parameter_list|()
function_decl|;
specifier|static
name|void
name|setSkipCurrentTest
parameter_list|(
name|bool
name|value
parameter_list|)
function_decl|;
specifier|static
name|bool
name|skipCurrentTest
parameter_list|()
function_decl|;
specifier|static
name|void
name|setCurrentAppname
parameter_list|(
specifier|const
name|char
modifier|*
name|appname
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|currentAppname
parameter_list|()
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTestResult
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
