begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BASELINETEST_H
end_ifndef
begin_define
DECL|macro|BASELINETEST_H
define|#
directive|define
name|BASELINETEST_H
end_define
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_decl_stmt
name|namespace
name|QBaselineTest
block|{
name|void
name|setAutoMode
parameter_list|(
name|bool
name|mode
parameter_list|)
function_decl|;
name|void
name|setSimFail
parameter_list|(
name|bool
name|fail
parameter_list|)
function_decl|;
name|void
name|handleCmdLineArgs
parameter_list|(
name|int
modifier|*
name|argcp
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argvp
parameter_list|)
function_decl|;
name|void
name|addClientProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|connectToBaselineServer
parameter_list|(
name|QByteArray
modifier|*
name|msg
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|testProject
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|testCase
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|bool
name|checkImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|quint16
name|checksum
parameter_list|,
name|QByteArray
modifier|*
name|msg
parameter_list|,
name|bool
modifier|*
name|error
parameter_list|,
name|int
name|manualdatatag
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|testImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|img
parameter_list|,
name|QByteArray
modifier|*
name|msg
parameter_list|,
name|bool
modifier|*
name|error
parameter_list|)
function_decl|;
name|QTestData
modifier|&
name|newRow
parameter_list|(
specifier|const
name|char
modifier|*
name|dataTag
parameter_list|,
name|quint16
name|checksum
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|disconnectFromBaselineServer
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_define
DECL|macro|QBASELINE_CHECK_SUM
define|#
directive|define
name|QBASELINE_CHECK_SUM
parameter_list|(
name|image
parameter_list|,
name|name
parameter_list|,
name|checksum
parameter_list|)
define|\
value|do {\     QByteArray _msg;\     bool _err = false;\     if (!QBaselineTest::checkImage((image), (name), (checksum),&_msg,&_err)) {\         QFAIL(_msg.constData());\     } else if (_err) {\         QSKIP(_msg.constData());\     }\ } while (0)
end_define
begin_define
DECL|macro|QBASELINE_CHECK
define|#
directive|define
name|QBASELINE_CHECK
parameter_list|(
name|image
parameter_list|,
name|name
parameter_list|)
value|QBASELINE_CHECK_SUM(image, name, 0)
end_define
begin_define
DECL|macro|QBASELINE_TEST
define|#
directive|define
name|QBASELINE_TEST
parameter_list|(
name|image
parameter_list|)
define|\
value|do {\     QByteArray _msg;\     bool _err = false;\     if (!QBaselineTest::testImage((image),&_msg,&_err)) {\         QFAIL(_msg.constData());\     } else if (_err) {\         QSKIP(_msg.constData());\     }\ } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BASELINETEST_H
end_comment
end_unit
