begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkAccessManager>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkConfigurationManager>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QNetworkAccessManager::NetworkAccessibility
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QNetworkAccessManager
class|class
name|tst_QNetworkAccessManager
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QNetworkAccessManager
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|networkAccessible
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QNetworkAccessManager
name|tst_QNetworkAccessManager
operator|::
name|tst_QNetworkAccessManager
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|networkAccessible
name|void
name|tst_QNetworkAccessManager
operator|::
name|networkAccessible
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|qRegisterMetaType
argument_list|<
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
argument_list|>
argument_list|(
literal|"QNetworkAccessManager::NetworkAccessibility"
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|networkAccessibleChanged
argument_list|(
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|manager
operator|.
name|networkAccessible
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|UnknownAccessibility
argument_list|)
expr_stmt|;
name|manager
operator|.
name|setNetworkAccessible
argument_list|(
name|QNetworkAccessManager
operator|::
name|NotAccessible
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|value
argument_list|<
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
argument_list|>
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|NotAccessible
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|manager
operator|.
name|networkAccessible
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|NotAccessible
argument_list|)
expr_stmt|;
name|manager
operator|.
name|setNetworkAccessible
argument_list|(
name|QNetworkAccessManager
operator|::
name|Accessible
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|value
argument_list|<
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
argument_list|>
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|UnknownAccessibility
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|manager
operator|.
name|networkAccessible
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|UnknownAccessibility
argument_list|)
expr_stmt|;
name|QNetworkConfigurationManager
name|configManager
decl_stmt|;
name|QNetworkConfiguration
name|defaultConfig
init|=
name|configManager
operator|.
name|defaultConfiguration
argument_list|()
decl_stmt|;
if|if
condition|(
name|defaultConfig
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|manager
operator|.
name|setConfiguration
argument_list|(
name|defaultConfig
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|value
argument_list|<
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
argument_list|>
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|Accessible
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|manager
operator|.
name|networkAccessible
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|Accessible
argument_list|)
expr_stmt|;
name|manager
operator|.
name|setNetworkAccessible
argument_list|(
name|QNetworkAccessManager
operator|::
name|NotAccessible
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
argument_list|(
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|,
name|QNetworkAccessManager
operator|::
name|NotAccessible
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|manager
operator|.
name|networkAccessible
argument_list|()
argument_list|,
name|QNetworkAccessManager
operator|::
name|NotAccessible
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkAccessManager
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkaccessmanager.moc"
end_include
end_unit
