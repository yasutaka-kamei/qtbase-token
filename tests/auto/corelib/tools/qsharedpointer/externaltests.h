begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEST_EXTERNAL_TESTS_H
end_ifndef
begin_define
DECL|macro|QTEST_EXTERNAL_TESTS_H
define|#
directive|define
name|QTEST_EXTERNAL_TESTS_H
end_define
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QTest
block|{
name|class
name|QExternalTestPrivate
decl_stmt|;
name|class
name|QExternalTest
block|{
name|public
label|:
name|QExternalTest
argument_list|()
expr_stmt|;
operator|~
name|QExternalTest
argument_list|()
expr_stmt|;
enum|enum
name|Stage
block|{
name|FileStage
block|,
name|QmakeStage
block|,
name|CompilationStage
block|,
name|LinkStage
block|,
name|RunStage
block|}
enum|;
enum|enum
name|QtModule
block|{
name|QtCore
init|=
literal|0x0001
block|,
name|QtGui
init|=
literal|0x0002
block|,
name|QtNetwork
init|=
literal|0x0004
block|,
name|QtXml
init|=
literal|0x0008
block|,
name|QtXmlPatterns
init|=
literal|0x0010
block|,
name|QtOpenGL
init|=
literal|0x0020
block|,
name|QtSql
init|=
literal|0x0040
block|,
name|QtSvg
init|=
literal|0x0080
block|,
name|QtScript
init|=
literal|0x0100
block|,
name|QtTest
init|=
literal|0x0200
block|,
name|QtDBus
init|=
literal|0x0400
block|,
name|QtWebKit
init|=
literal|0x0800
block|,
name|Phonon
init|=
literal|0x1000
comment|// odd man out
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
name|QtModules
argument_list|,
name|QtModule
argument_list|)
expr|enum
name|ApplicationType
block|{
name|AutoApplication
block|,
name|Applicationless
block|,
name|QCoreApplication
block|,
name|QApplicationTty
block|,
name|QApplicationGuiClient
block|,
name|QApplicationGuiServer
block|}
expr_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|qmakeSettings
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setQmakeSettings
argument_list|(
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|settings
argument_list|)
decl_stmt|;
name|QtModules
name|qtModules
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setQtModules
parameter_list|(
name|QtModules
name|modules
parameter_list|)
function_decl|;
name|ApplicationType
name|applicationType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setApplicationType
parameter_list|(
name|ApplicationType
name|type
parameter_list|)
function_decl|;
name|QStringList
name|extraProgramSources
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setExtraProgramSources
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
function_decl|;
name|QByteArray
name|programHeader
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setProgramHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|header
parameter_list|)
function_decl|;
comment|// execution:
name|bool
name|tryCompile
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
function_decl|;
name|bool
name|tryLink
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
function_decl|;
name|bool
name|tryRun
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
function_decl|;
name|bool
name|tryCompileFail
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
function_decl|;
name|bool
name|tryLinkFail
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
function_decl|;
name|bool
name|tryRunFail
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
function_decl|;
name|Stage
name|failedStage
argument_list|()
specifier|const
expr_stmt|;
name|int
name|exitCode
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|fullProgramSource
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|standardOutput
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|standardError
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorReport
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QExternalTestPrivate
modifier|*
specifier|const
name|d
decl_stmt|;
block|}
empty_stmt|;
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QExternalTest::QtModules
argument_list|)
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
