begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QTemporaryDir>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QtNetwork>
end_include
begin_include
include|#
directive|include
file|"../../../network-settings.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfigmanager.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfiguration.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworksession.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_define
DECL|macro|TESTFILE
define|#
directive|define
name|TESTFILE
value|QLatin1String("http://") + QtNetworkSettings::serverName() + QLatin1String("/qtest/cgi-bin/")
end_define
begin_class
DECL|class|tst_QAbstractNetworkCache
class|class
name|tst_QAbstractNetworkCache
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QAbstractNetworkCache
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QAbstractNetworkCache
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|expires_data
parameter_list|()
function_decl|;
name|void
name|expires
parameter_list|()
function_decl|;
name|void
name|expiresSynchronous_data
parameter_list|()
function_decl|;
name|void
name|expiresSynchronous
parameter_list|()
function_decl|;
name|void
name|lastModified_data
parameter_list|()
function_decl|;
name|void
name|lastModified
parameter_list|()
function_decl|;
name|void
name|lastModifiedSynchronous_data
parameter_list|()
function_decl|;
name|void
name|lastModifiedSynchronous
parameter_list|()
function_decl|;
name|void
name|etag_data
parameter_list|()
function_decl|;
name|void
name|etag
parameter_list|()
function_decl|;
name|void
name|etagSynchronous_data
parameter_list|()
function_decl|;
name|void
name|etagSynchronous
parameter_list|()
function_decl|;
name|void
name|cacheControl_data
parameter_list|()
function_decl|;
name|void
name|cacheControl
parameter_list|()
function_decl|;
name|void
name|cacheControlSynchronous_data
parameter_list|()
function_decl|;
name|void
name|cacheControlSynchronous
parameter_list|()
function_decl|;
name|void
name|deleteCache
parameter_list|()
function_decl|;
private|private:
name|void
name|runTest
parameter_list|()
function_decl|;
name|void
name|checkSynchronous
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
DECL|member|netConfMan
name|QNetworkConfigurationManager
modifier|*
name|netConfMan
decl_stmt|;
DECL|member|networkConfiguration
name|QNetworkConfiguration
name|networkConfiguration
decl_stmt|;
DECL|member|networkSession
name|QScopedPointer
argument_list|<
name|QNetworkSession
argument_list|>
name|networkSession
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_class
DECL|class|NetworkDiskCache
class|class
name|NetworkDiskCache
super|:
specifier|public
name|QNetworkDiskCache
block|{
name|Q_OBJECT
public|public:
DECL|function|NetworkDiskCache
name|NetworkDiskCache
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QNetworkDiskCache
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|tempDir
argument_list|(
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/tst_qabstractnetworkcache.XXXXXX"
argument_list|)
argument_list|)
member_init_list|,
name|gotData
argument_list|(
literal|false
argument_list|)
block|{
name|setCacheDirectory
argument_list|(
name|tempDir
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|data
name|QIODevice
modifier|*
name|data
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|gotData
operator|=
literal|true
expr_stmt|;
return|return
name|QNetworkDiskCache
operator|::
name|data
argument_list|(
name|url
argument_list|)
return|;
block|}
DECL|member|tempDir
name|QTemporaryDir
name|tempDir
decl_stmt|;
DECL|member|gotData
name|bool
name|gotData
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QAbstractNetworkCache
name|tst_QAbstractNetworkCache
operator|::
name|tst_QAbstractNetworkCache
parameter_list|()
block|{
name|QCoreApplication
operator|::
name|setOrganizationName
argument_list|(
name|QLatin1String
argument_list|(
literal|"QtProject"
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|setApplicationName
argument_list|(
name|QLatin1String
argument_list|(
literal|"autotest_qabstractnetworkcache"
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|setApplicationVersion
argument_list|(
name|QLatin1String
argument_list|(
literal|"1.0"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~tst_QAbstractNetworkCache
name|tst_QAbstractNetworkCache
operator|::
name|~
name|tst_QAbstractNetworkCache
parameter_list|()
block|{ }
end_destructor
begin_decl_stmt
DECL|variable|AlwaysTrue
specifier|static
name|bool
name|AlwaysTrue
init|=
literal|true
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AlwaysFalse
specifier|static
name|bool
name|AlwaysFalse
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QNetworkRequest::CacheLoadControl
argument_list|)
end_macro
begin_function
DECL|function|initTestCase
name|void
name|tst_QAbstractNetworkCache
operator|::
name|initTestCase
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QtNetworkSettings
operator|::
name|verifyTestNetworkSettings
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"No network test server available"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|netConfMan
operator|=
operator|new
name|QNetworkConfigurationManager
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|networkConfiguration
operator|=
name|netConfMan
operator|->
name|defaultConfiguration
argument_list|()
expr_stmt|;
name|networkSession
operator|.
name|reset
argument_list|(
operator|new
name|QNetworkSession
argument_list|(
name|networkConfiguration
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|networkSession
operator|->
name|isOpen
argument_list|()
condition|)
block|{
name|networkSession
operator|->
name|open
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|networkSession
operator|->
name|waitForOpened
argument_list|(
literal|30000
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|expires_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|expires_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkRequest
operator|::
name|CacheLoadControl
argument_list|>
argument_list|(
literal|"cacheLoadControl"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"url"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"fetchFromCache"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_expires304.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_expires304.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_expires304.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_expires304.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"500-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_expires500.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"500-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_expires500.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"500-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_expires500.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"500-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_expires500.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_expires200.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_expires200.cgi"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_expires200.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_expires200.cgi"
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expires
name|void
name|tst_QAbstractNetworkCache
operator|::
name|expires
parameter_list|()
block|{
name|runTest
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expiresSynchronous_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|expiresSynchronous_data
parameter_list|()
block|{
name|expires_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expiresSynchronous
name|void
name|tst_QAbstractNetworkCache
operator|::
name|expiresSynchronous
parameter_list|()
block|{
name|checkSynchronous
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lastModified_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|lastModified_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkRequest
operator|::
name|CacheLoadControl
argument_list|>
argument_list|(
literal|"cacheLoadControl"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"url"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"fetchFromCache"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_lastModified304.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_lastModified304.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_lastModified304.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_lastModified304.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_lastModified200.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_lastModified200.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_lastModified200.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_lastModified200.cgi"
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lastModified
name|void
name|tst_QAbstractNetworkCache
operator|::
name|lastModified
parameter_list|()
block|{
name|runTest
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lastModifiedSynchronous_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|lastModifiedSynchronous_data
parameter_list|()
block|{
name|tst_QAbstractNetworkCache
operator|::
name|lastModified_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lastModifiedSynchronous
name|void
name|tst_QAbstractNetworkCache
operator|::
name|lastModifiedSynchronous
parameter_list|()
block|{
name|checkSynchronous
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|etag_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|etag_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkRequest
operator|::
name|CacheLoadControl
argument_list|>
argument_list|(
literal|"cacheLoadControl"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"url"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"fetchFromCache"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_etag304.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_etag304.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_etag304.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_etag304.cgi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_etag200.cgi"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_etag200.cgi"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_etag200.cgi"
operator|<<
name|AlwaysTrue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_etag200.cgi"
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|etag
name|void
name|tst_QAbstractNetworkCache
operator|::
name|etag
parameter_list|()
block|{
name|runTest
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|etagSynchronous_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|etagSynchronous_data
parameter_list|()
block|{
name|tst_QAbstractNetworkCache
operator|::
name|etag_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|etagSynchronous
name|void
name|tst_QAbstractNetworkCache
operator|::
name|etagSynchronous
parameter_list|()
block|{
name|checkSynchronous
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cacheControl_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|cacheControl_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkRequest
operator|::
name|CacheLoadControl
argument_list|>
argument_list|(
literal|"cacheLoadControl"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"url"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"fetchFromCache"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_cachecontrol.cgi?max-age=-1"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_cachecontrol-expire.cgi"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_cachecontrol.cgi?no-cache"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_cachecontrol.cgi?no-cache"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-4"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_cachecontrol.cgi?no-cache"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"200-5"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_cachecontrol.cgi?no-cache"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-0"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_cachecontrol.cgi?max-age=1000"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-1"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysNetwork
operator|<<
literal|"httpcachetest_cachecontrol.cgi?max-age=1000, must-revalidate"
operator|<<
name|AlwaysFalse
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-2"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_cachecontrol.cgi?max-age=1000, must-revalidate"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-3"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|AlwaysCache
operator|<<
literal|"httpcachetest_cachecontrol.cgi?max-age=1000, must-revalidate"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-4"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_cachecontrol.cgi?max-age=1000, must-revalidate"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-2b"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferNetwork
operator|<<
literal|"httpcachetest_cachecontrol200.cgi?private, max-age=1000"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"304-4b"
argument_list|)
operator|<<
name|QNetworkRequest
operator|::
name|PreferCache
operator|<<
literal|"httpcachetest_cachecontrol200.cgi?private, max-age=1000"
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cacheControl
name|void
name|tst_QAbstractNetworkCache
operator|::
name|cacheControl
parameter_list|()
block|{
name|runTest
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cacheControlSynchronous_data
name|void
name|tst_QAbstractNetworkCache
operator|::
name|cacheControlSynchronous_data
parameter_list|()
block|{
name|tst_QAbstractNetworkCache
operator|::
name|cacheControl_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cacheControlSynchronous
name|void
name|tst_QAbstractNetworkCache
operator|::
name|cacheControlSynchronous
parameter_list|()
block|{
name|checkSynchronous
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runTest
name|void
name|tst_QAbstractNetworkCache
operator|::
name|runTest
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkRequest
operator|::
name|CacheLoadControl
argument_list|,
name|cacheLoadControl
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|url
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|fetchFromCache
argument_list|)
expr_stmt|;
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|NetworkDiskCache
modifier|*
name|diskCache
init|=
operator|new
name|NetworkDiskCache
argument_list|(
operator|&
name|manager
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|diskCache
operator|->
name|tempDir
operator|.
name|isValid
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|diskCache
operator|->
name|tempDir
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|manager
operator|.
name|setCache
argument_list|(
name|diskCache
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|diskCache
operator|->
name|gotData
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QUrl
name|realUrl
init|=
name|url
operator|.
name|contains
argument_list|(
literal|"://"
argument_list|)
condition|?
name|url
else|:
name|TESTFILE
operator|+
name|url
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|realUrl
argument_list|)
decl_stmt|;
comment|// prime the cache
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|QSignalSpy
name|downloaded1
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QTRY_COMPARE
argument_list|(
name|downloaded1
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|diskCache
operator|->
name|gotData
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QByteArray
name|goodData
init|=
name|reply
operator|->
name|readAll
argument_list|()
decl_stmt|;
name|request
operator|.
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|CacheLoadControlAttribute
argument_list|,
name|cacheLoadControl
argument_list|)
expr_stmt|;
comment|// should be in the cache now
name|QNetworkReply
modifier|*
name|reply2
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|QSignalSpy
name|downloaded2
argument_list|(
name|reply2
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QTRY_COMPARE
argument_list|(
name|downloaded2
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QByteArray
name|secondData
init|=
name|reply2
operator|->
name|readAll
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|fetchFromCache
operator|&&
name|cacheLoadControl
operator|==
name|QNetworkRequest
operator|::
name|AlwaysCache
condition|)
block|{
name|QCOMPARE
argument_list|(
name|reply2
operator|->
name|error
argument_list|()
argument_list|,
name|QNetworkReply
operator|::
name|ContentNotFoundError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|secondData
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|reply2
operator|->
name|error
argument_list|()
argument_list|,
name|QNetworkReply
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
argument_list|(
name|secondData
argument_list|)
argument_list|,
name|QString
argument_list|(
name|goodData
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|secondData
argument_list|,
name|goodData
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|reply2
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpStatusCodeAttribute
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|200
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fetchFromCache
condition|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|rawHeaderList
init|=
name|reply
operator|->
name|rawHeaderList
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|rawHeaderList2
init|=
name|reply2
operator|->
name|rawHeaderList
argument_list|()
decl_stmt|;
name|std
operator|::
name|sort
argument_list|(
name|rawHeaderList
operator|.
name|begin
argument_list|()
argument_list|,
name|rawHeaderList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|std
operator|::
name|sort
argument_list|(
name|rawHeaderList2
operator|.
name|begin
argument_list|()
argument_list|,
name|rawHeaderList2
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|diskCache
operator|->
name|gotData
argument_list|,
name|fetchFromCache
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkSynchronous
name|void
name|tst_QAbstractNetworkCache
operator|::
name|checkSynchronous
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"not working yet, see QTBUG-15221"
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QNetworkRequest
operator|::
name|CacheLoadControl
argument_list|,
name|cacheLoadControl
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|url
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|fetchFromCache
argument_list|)
expr_stmt|;
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|NetworkDiskCache
modifier|*
name|diskCache
init|=
operator|new
name|NetworkDiskCache
argument_list|(
operator|&
name|manager
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|diskCache
operator|->
name|tempDir
operator|.
name|isValid
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|diskCache
operator|->
name|tempDir
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|manager
operator|.
name|setCache
argument_list|(
name|diskCache
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|diskCache
operator|->
name|gotData
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QUrl
name|realUrl
init|=
name|url
operator|.
name|contains
argument_list|(
literal|"://"
argument_list|)
condition|?
name|url
else|:
name|TESTFILE
operator|+
name|url
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|realUrl
argument_list|)
decl_stmt|;
name|request
operator|.
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|SynchronousRequestAttribute
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// prime the cache
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|reply
operator|->
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
comment|// synchronous
name|QCOMPARE
argument_list|(
name|diskCache
operator|->
name|gotData
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QByteArray
name|goodData
init|=
name|reply
operator|->
name|readAll
argument_list|()
decl_stmt|;
name|request
operator|.
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|CacheLoadControlAttribute
argument_list|,
name|cacheLoadControl
argument_list|)
expr_stmt|;
comment|// should be in the cache now
name|QNetworkReply
modifier|*
name|reply2
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|reply2
operator|->
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
comment|// synchronous
name|QByteArray
name|secondData
init|=
name|reply2
operator|->
name|readAll
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|fetchFromCache
operator|&&
name|cacheLoadControl
operator|==
name|QNetworkRequest
operator|::
name|AlwaysCache
condition|)
block|{
name|QCOMPARE
argument_list|(
name|reply2
operator|->
name|error
argument_list|()
argument_list|,
name|QNetworkReply
operator|::
name|ContentNotFoundError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|secondData
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|reply2
operator|->
name|error
argument_list|()
operator|!=
name|QNetworkReply
operator|::
name|NoError
condition|)
name|qDebug
argument_list|()
operator|<<
name|reply2
operator|->
name|errorString
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|reply2
operator|->
name|error
argument_list|()
argument_list|,
name|QNetworkReply
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
argument_list|(
name|secondData
argument_list|)
argument_list|,
name|QString
argument_list|(
name|goodData
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|secondData
argument_list|,
name|goodData
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|reply2
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpStatusCodeAttribute
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|200
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fetchFromCache
condition|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|rawHeaderList
init|=
name|reply
operator|->
name|rawHeaderList
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|rawHeaderList2
init|=
name|reply2
operator|->
name|rawHeaderList
argument_list|()
decl_stmt|;
name|std
operator|::
name|sort
argument_list|(
name|rawHeaderList
operator|.
name|begin
argument_list|()
argument_list|,
name|rawHeaderList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|std
operator|::
name|sort
argument_list|(
name|rawHeaderList2
operator|.
name|begin
argument_list|()
argument_list|,
name|rawHeaderList2
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|diskCache
operator|->
name|gotData
argument_list|,
name|fetchFromCache
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteCache
name|void
name|tst_QAbstractNetworkCache
operator|::
name|deleteCache
parameter_list|()
block|{
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|NetworkDiskCache
modifier|*
name|diskCache
init|=
operator|new
name|NetworkDiskCache
argument_list|(
operator|&
name|manager
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|diskCache
operator|->
name|tempDir
operator|.
name|isValid
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|diskCache
operator|->
name|tempDir
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|manager
operator|.
name|setCache
argument_list|(
name|diskCache
argument_list|)
expr_stmt|;
name|QString
name|url
init|=
literal|"httpcachetest_cachecontrol.cgi?max-age=1000"
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
argument_list|(
name|TESTFILE
operator|+
name|url
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|QSignalSpy
name|downloaded1
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|setCache
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|downloaded1
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractNetworkCache
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractnetworkcache.moc"
end_include
end_unit
