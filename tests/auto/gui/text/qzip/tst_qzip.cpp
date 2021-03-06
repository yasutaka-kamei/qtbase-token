begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<private/qzipwriter_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qzipreader_p.h>
end_include
begin_class
DECL|class|tst_QZip
class|class
name|tst_QZip
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|basicUnpack
parameter_list|()
function_decl|;
name|void
name|symlinks
parameter_list|()
function_decl|;
name|void
name|readTest
parameter_list|()
function_decl|;
name|void
name|createArchive
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|basicUnpack
name|void
name|tst_QZip
operator|::
name|basicUnpack
parameter_list|()
block|{
name|QZipReader
name|zip
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"/testdata/test.zip"
argument_list|)
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QZipReader
operator|::
name|FileInfo
argument_list|>
name|files
init|=
name|zip
operator|.
name|fileInfoList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|files
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QZipReader
operator|::
name|FileInfo
name|fi
init|=
name|files
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|filePath
argument_list|,
name|QString
argument_list|(
literal|"test/"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|fi
operator|.
name|isDir
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|fi
operator|.
name|isFile
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|fi
operator|.
name|isSymLink
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|permissions
argument_list|,
name|QFile
operator|::
name|Permissions
argument_list|(
name|QFile
operator|::
name|ReadOwner
operator||
name|QFile
operator|::
name|WriteOwner
operator||
name|QFile
operator|::
name|ExeOwner
operator||
name|QFile
operator|::
name|ReadUser
operator||
name|QFile
operator|::
name|WriteUser
operator||
name|QFile
operator|::
name|ExeUser
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|lastModified
argument_list|,
name|QDateTime
operator|::
name|fromString
argument_list|(
literal|"2005.11.11 13:08:02"
argument_list|,
literal|"yyyy.MM.dd HH:mm:ss"
argument_list|)
argument_list|)
expr_stmt|;
name|fi
operator|=
name|files
operator|.
name|at
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|filePath
argument_list|,
name|QString
argument_list|(
literal|"test/test.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|fi
operator|.
name|isDir
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|fi
operator|.
name|isFile
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|fi
operator|.
name|isSymLink
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|permissions
operator|==
name|QFile
operator|::
name|Permissions
argument_list|(
name|QFile
operator|::
name|ReadOwner
operator||
name|QFile
operator|::
name|WriteOwner
operator||
name|QFile
operator|::
name|ReadUser
operator||
name|QFile
operator|::
name|WriteUser
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|lastModified
argument_list|,
name|QDateTime
operator|::
name|fromString
argument_list|(
literal|"2005.11.11 13:08:02"
argument_list|,
literal|"yyyy.MM.dd HH:mm:ss"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|zip
operator|.
name|fileData
argument_list|(
literal|"test/test.txt"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"content\n"
argument_list|)
argument_list|)
expr_stmt|;
name|fi
operator|=
name|zip
operator|.
name|entryInfoAt
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fi
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|symlinks
name|void
name|tst_QZip
operator|::
name|symlinks
parameter_list|()
block|{
name|QZipReader
name|zip
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"/testdata/symlink.zip"
argument_list|)
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QZipReader
operator|::
name|FileInfo
argument_list|>
name|files
init|=
name|zip
operator|.
name|fileInfoList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|files
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QZipReader
operator|::
name|FileInfo
name|fi
init|=
name|files
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|filePath
argument_list|,
name|QString
argument_list|(
literal|"symlink"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fi
operator|.
name|isDir
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fi
operator|.
name|isFile
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|isSymLink
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|zip
operator|.
name|fileData
argument_list|(
literal|"symlink"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"destination"
argument_list|)
argument_list|)
expr_stmt|;
name|fi
operator|=
name|files
operator|.
name|at
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|filePath
argument_list|,
name|QString
argument_list|(
literal|"destination"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fi
operator|.
name|isDir
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fi
operator|.
name|isFile
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fi
operator|.
name|isSymLink
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readTest
name|void
name|tst_QZip
operator|::
name|readTest
parameter_list|()
block|{
name|QZipReader
name|zip
argument_list|(
literal|"foobar.zip"
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
comment|// non existing file.
name|QVector
argument_list|<
name|QZipReader
operator|::
name|FileInfo
argument_list|>
name|files
init|=
name|zip
operator|.
name|fileInfoList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|files
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QByteArray
name|b
init|=
name|zip
operator|.
name|fileData
argument_list|(
literal|"foobar"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|b
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createArchive
name|void
name|tst_QZip
operator|::
name|createArchive
parameter_list|()
block|{
name|QBuffer
name|buffer
decl_stmt|;
name|QZipWriter
name|zip
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|QByteArray
name|fileContents
argument_list|(
literal|"simple file contents\nline2\n"
argument_list|)
decl_stmt|;
name|zip
operator|.
name|addFile
argument_list|(
literal|"My Filename"
argument_list|,
name|fileContents
argument_list|)
expr_stmt|;
name|zip
operator|.
name|close
argument_list|()
expr_stmt|;
name|QByteArray
name|zipFile
init|=
name|buffer
operator|.
name|buffer
argument_list|()
decl_stmt|;
comment|// QFile f("createArchiveTest.zip"); f.open(QIODevice::WriteOnly); f.write(zipFile); f.close();
name|QBuffer
name|buffer2
argument_list|(
operator|&
name|zipFile
argument_list|)
decl_stmt|;
name|QZipReader
name|zip2
argument_list|(
operator|&
name|buffer2
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QZipReader
operator|::
name|FileInfo
argument_list|>
name|files
init|=
name|zip2
operator|.
name|fileInfoList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|files
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QZipReader
operator|::
name|FileInfo
name|file
init|=
name|files
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|filePath
argument_list|,
name|QString
argument_list|(
literal|"My Filename"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|file
operator|.
name|isDir
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|file
operator|.
name|isFile
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uint
argument_list|(
name|file
operator|.
name|isSymLink
argument_list|)
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|permissions
argument_list|,
name|QFile
operator|::
name|Permissions
argument_list|(
name|QFile
operator|::
name|ReadOwner
operator||
name|QFile
operator|::
name|WriteOwner
operator||
name|QFile
operator|::
name|ReadUser
operator||
name|QFile
operator|::
name|WriteUser
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|size
argument_list|,
operator|(
name|long
name|long
operator|)
literal|27
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|zip2
operator|.
name|fileData
argument_list|(
literal|"My Filename"
argument_list|)
argument_list|,
name|fileContents
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QZip
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qzip.moc"
end_include
end_unit
