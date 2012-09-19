begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Giuseppe D'Angelo<dangelog@gmail.com> ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QProcess>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDirIterator>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QResource>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_typedef
DECL|typedef|QStringMap
typedef|typedef
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|QStringMap
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QStringMap
argument_list|)
end_macro
begin_class
DECL|class|tst_rcc
class|class
name|tst_rcc
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|rcc_data
parameter_list|()
function_decl|;
name|void
name|rcc
parameter_list|()
function_decl|;
name|void
name|binary_data
parameter_list|()
function_decl|;
name|void
name|binary
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_rcc
operator|::
name|initTestCase
parameter_list|()
block|{
comment|// rcc uses a QHash to store files in the resource system.
comment|// we must force a certain hash order when testing or tst_rcc will fail, see QTBUG-25078
name|QVERIFY
argument_list|(
name|qputenv
argument_list|(
literal|"QT_RCC_TEST"
argument_list|,
literal|"1"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findExpectedFile
name|QString
name|findExpectedFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|base
parameter_list|)
block|{
name|QString
name|expectedrccfile
init|=
name|base
decl_stmt|;
comment|// Must be updated with each minor release.
if|if
condition|(
name|QFileInfo
argument_list|(
name|expectedrccfile
operator|+
name|QLatin1String
argument_list|(
literal|".450"
argument_list|)
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
name|expectedrccfile
operator|+=
name|QLatin1String
argument_list|(
literal|".450"
argument_list|)
expr_stmt|;
return|return
name|expectedrccfile
return|;
block|}
end_function
begin_function
DECL|function|doCompare
specifier|static
name|QString
name|doCompare
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|actual
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|expected
parameter_list|)
block|{
if|if
condition|(
name|actual
operator|.
name|size
argument_list|()
operator|!=
name|expected
operator|.
name|size
argument_list|()
condition|)
block|{
return|return
name|QString
argument_list|(
literal|"Length count different: actual: %1, expected: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|actual
operator|.
name|size
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|expected
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
name|QByteArray
name|ba
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|n
init|=
name|expected
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|expected
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"IGNORE:"
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|expected
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|!=
name|actual
operator|.
name|at
argument_list|(
name|i
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"LINES"
operator|<<
name|i
operator|<<
literal|"DIFFER"
expr_stmt|;
name|ba
operator|.
name|append
argument_list|(
literal|"\n<<<<<< actual\n"
operator|+
name|actual
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|"\n======\n"
operator|+
name|expected
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|"\n>>>>>> expected\n"
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ba
return|;
block|}
end_function
begin_function
DECL|function|rcc_data
name|void
name|tst_rcc
operator|::
name|rcc_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"directory"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"qrcfile"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QString
name|dataPath
init|=
name|QFINDTESTDATA
argument_list|(
literal|"data/images/"
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataPath
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"data path not found"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"images"
argument_list|)
operator|<<
name|dataPath
operator|<<
literal|"images.qrc"
operator|<<
literal|"images.expected"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rcc
name|void
name|tst_rcc
operator|::
name|rcc
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|directory
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|qrcfile
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|setCurrent
argument_list|(
name|directory
argument_list|)
condition|)
block|{
name|QString
name|message
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Unable to cd from '%1' to '%2'"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|,
name|directory
argument_list|)
decl_stmt|;
name|QFAIL
argument_list|(
name|qPrintable
argument_list|(
name|message
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// If the file expectedoutput.txt exists, compare the
comment|// console output with the content of that file
specifier|const
name|QString
name|expected2
init|=
name|findExpectedFile
argument_list|(
name|expected
argument_list|)
decl_stmt|;
name|QFile
name|expectedFile
argument_list|(
name|expected2
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|expectedFile
operator|.
name|exists
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"NO EXPECTATIONS? "
operator|<<
name|expected2
expr_stmt|;
return|return;
block|}
comment|// Launch
specifier|const
name|QString
name|command
init|=
name|QLatin1String
argument_list|(
literal|"rcc"
argument_list|)
decl_stmt|;
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
name|command
argument_list|,
name|QStringList
argument_list|(
name|qrcfile
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|process
operator|.
name|waitForFinished
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|path
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"PATH"
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|message
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"'%1' could not be found when run from '%2'. Path: '%3' "
argument_list|)
operator|.
name|arg
argument_list|(
name|command
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|,
name|path
argument_list|)
decl_stmt|;
name|QFAIL
argument_list|(
name|qPrintable
argument_list|(
name|message
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QChar
name|cr
init|=
name|QLatin1Char
argument_list|(
literal|'\r'
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|err
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|process
operator|.
name|readAllStandardError
argument_list|()
argument_list|)
operator|.
name|remove
argument_list|(
name|cr
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|out
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|process
operator|.
name|readAllStandardOutput
argument_list|()
argument_list|)
operator|.
name|remove
argument_list|(
name|cr
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|err
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"UNEXPECTED STDERR CONTENTS: "
operator|<<
name|err
expr_stmt|;
name|QFAIL
argument_list|(
literal|"UNEXPECTED STDERR CONTENTS"
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QChar
name|nl
init|=
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
name|actualLines
init|=
name|out
operator|.
name|split
argument_list|(
name|nl
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|expectedFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|expectedLines
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|expectedFile
operator|.
name|readAll
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|nl
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|diff
init|=
name|doCompare
argument_list|(
name|actualLines
argument_list|,
name|expectedLines
argument_list|)
decl_stmt|;
if|if
condition|(
name|diff
operator|.
name|size
argument_list|()
condition|)
name|QFAIL
argument_list|(
name|qPrintable
argument_list|(
name|diff
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createRccBinaryData
specifier|static
name|void
name|createRccBinaryData
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|qrcFileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|rccFileName
parameter_list|)
block|{
name|QString
name|currentDir
init|=
name|QDir
operator|::
name|currentPath
argument_list|()
decl_stmt|;
name|QDir
operator|::
name|setCurrent
argument_list|(
name|baseDir
argument_list|)
expr_stmt|;
name|QProcess
name|rccProcess
decl_stmt|;
name|rccProcess
operator|.
name|start
argument_list|(
literal|"rcc"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"-binary"
operator|<<
literal|"-o"
operator|<<
name|rccFileName
operator|<<
name|qrcFileName
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|rccProcess
operator|.
name|waitForFinished
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|QString
name|errorString
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Could not start rcc (is it in PATH?): %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|rccProcess
operator|.
name|errorString
argument_list|()
argument_list|)
decl_stmt|;
name|QFAIL
argument_list|(
name|qPrintable
argument_list|(
name|errorString
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QByteArray
name|output
init|=
name|rccProcess
operator|.
name|readAllStandardOutput
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|output
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|errorMessage
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"rcc stdout: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|output
argument_list|)
argument_list|)
decl_stmt|;
name|QWARN
argument_list|(
name|qPrintable
argument_list|(
name|errorMessage
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|output
operator|=
name|rccProcess
operator|.
name|readAllStandardError
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|output
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|errorMessage
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"rcc stderr: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|output
argument_list|)
argument_list|)
decl_stmt|;
name|QWARN
argument_list|(
name|qPrintable
argument_list|(
name|errorMessage
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QDir
operator|::
name|setCurrent
argument_list|(
name|currentDir
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readLinesFromFile
specifier|static
name|QStringList
name|readLinesFromFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|QWARN
argument_list|(
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Could not open testdata file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|lines
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
return|return
name|lines
return|;
block|}
end_function
begin_function
DECL|function|readExpectedFiles
specifier|static
name|QStringMap
name|readExpectedFiles
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QStringMap
name|expectedFiles
decl_stmt|;
name|QStringList
name|lines
init|=
name|readLinesFromFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|line
decl|,
name|lines
control|)
block|{
name|QString
name|resourceFileName
init|=
name|line
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
operator|::
name|SectionSkipEmpty
argument_list|)
decl_stmt|;
name|QString
name|actualFileName
init|=
name|line
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|QString
operator|::
name|SectionSkipEmpty
argument_list|)
decl_stmt|;
name|expectedFiles
index|[
name|resourceFileName
index|]
operator|=
name|actualFileName
expr_stmt|;
block|}
return|return
name|expectedFiles
return|;
block|}
end_function
begin_comment
comment|/*     The following test looks for all *.qrc files under data/binary/. For each     .qrc file found, these files are processed (assuming the file found is     called "base.qrc"):      - base.qrc : processed by rcc; creates base.rcc     - base.locale : (optional) list of locales to test, one per line     - base.expected : list of pairs (file path in resource, path to real file),         one per line; the pair separated by a whitespace; the paths to real files         relative to data/binary/ (for testing the C locale)     - base.localeName.expected : for each localeName in the base.locale file,         as the above .expected file */
end_comment
begin_function
DECL|function|binary_data
name|void
name|tst_rcc
operator|::
name|binary_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"resourceFile"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QLocale
argument_list|>
argument_list|(
literal|"locale"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"baseDirectory"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringMap
argument_list|>
argument_list|(
literal|"expectedFiles"
argument_list|)
expr_stmt|;
name|QString
name|dataPath
init|=
name|QFINDTESTDATA
argument_list|(
literal|"data/binary/"
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataPath
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"data path not found"
argument_list|)
expr_stmt|;
name|QDirIterator
name|iter
argument_list|(
name|dataPath
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"*.qrc"
argument_list|)
argument_list|)
decl_stmt|;
while|while
condition|(
name|iter
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|iter
operator|.
name|next
argument_list|()
expr_stmt|;
name|QFileInfo
name|qrcFileInfo
init|=
name|iter
operator|.
name|fileInfo
argument_list|()
decl_stmt|;
name|QString
name|absoluteBaseName
init|=
name|QFileInfo
argument_list|(
name|qrcFileInfo
operator|.
name|absolutePath
argument_list|()
argument_list|,
name|qrcFileInfo
operator|.
name|baseName
argument_list|()
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
decl_stmt|;
name|QString
name|rccFileName
init|=
name|absoluteBaseName
operator|+
name|QLatin1String
argument_list|(
literal|".rcc"
argument_list|)
decl_stmt|;
name|createRccBinaryData
argument_list|(
name|dataPath
argument_list|,
name|qrcFileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|rccFileName
argument_list|)
expr_stmt|;
name|QString
name|localeFileName
init|=
name|absoluteBaseName
operator|+
name|QLatin1String
argument_list|(
literal|".locale"
argument_list|)
decl_stmt|;
name|QFile
name|localeFile
argument_list|(
name|localeFileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|localeFile
operator|.
name|exists
argument_list|()
condition|)
block|{
name|QStringList
name|locales
init|=
name|readLinesFromFile
argument_list|(
name|localeFileName
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|locale
decl|,
name|locales
control|)
block|{
name|QString
name|expectedFileName
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1.%2.%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|absoluteBaseName
argument_list|,
name|locale
argument_list|,
name|QLatin1String
argument_list|(
literal|"expected"
argument_list|)
argument_list|)
decl_stmt|;
name|QStringMap
name|expectedFiles
init|=
name|readExpectedFiles
argument_list|(
name|expectedFileName
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|qrcFileInfo
operator|.
name|baseName
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|locale
argument_list|)
argument_list|)
operator|<<
name|rccFileName
operator|<<
name|QLocale
argument_list|(
name|locale
argument_list|)
operator|<<
name|dataPath
operator|<<
name|expectedFiles
expr_stmt|;
block|}
block|}
comment|// always test for the C locale as well
name|QString
name|expectedFileName
init|=
name|absoluteBaseName
operator|+
name|QLatin1String
argument_list|(
literal|".expected"
argument_list|)
decl_stmt|;
name|QStringMap
name|expectedFiles
init|=
name|readExpectedFiles
argument_list|(
name|expectedFileName
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|qrcFileInfo
operator|.
name|baseName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"_C"
argument_list|)
argument_list|)
argument_list|)
operator|<<
name|rccFileName
operator|<<
name|QLocale
operator|::
name|c
argument_list|()
operator|<<
name|dataPath
operator|<<
name|expectedFiles
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|binary
name|void
name|tst_rcc
operator|::
name|binary
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|baseDirectory
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|resourceFile
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QLocale
argument_list|,
name|locale
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringMap
argument_list|,
name|expectedFiles
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|rootPrefix
init|=
name|QLatin1String
argument_list|(
literal|"/test_root/"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|resourceRootPrefix
init|=
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|+
name|rootPrefix
decl_stmt|;
name|QLocale
name|oldDefaultLocale
decl_stmt|;
name|QLocale
operator|::
name|setDefault
argument_list|(
name|locale
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFile
operator|::
name|exists
argument_list|(
name|resourceFile
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QResource
operator|::
name|registerResource
argument_list|(
name|resourceFile
argument_list|,
name|rootPrefix
argument_list|)
argument_list|)
expr_stmt|;
block|{
comment|// need to destroy the iterators on the resource, in order to be able to unregister it
comment|// read all the files inside the resources
name|QDirIterator
name|iter
argument_list|(
name|resourceRootPrefix
argument_list|,
name|QDir
operator|::
name|Files
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QString
argument_list|>
name|filesFound
decl_stmt|;
while|while
condition|(
name|iter
operator|.
name|hasNext
argument_list|()
condition|)
name|filesFound
operator|<<
name|iter
operator|.
name|next
argument_list|()
expr_stmt|;
comment|// add the test root prefix to the expected file names
name|QList
argument_list|<
name|QString
argument_list|>
name|expectedFileNames
init|=
name|expectedFiles
operator|.
name|keys
argument_list|()
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|i
init|=
name|expectedFileNames
operator|.
name|begin
argument_list|()
init|;
name|i
operator|<
name|expectedFileNames
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
comment|// poor man's canonicalPath, which doesn't work with resources
if|if
condition|(
operator|(
operator|*
name|i
operator|)
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
operator|(
operator|*
name|i
operator|)
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|*
name|i
operator|=
name|resourceRootPrefix
operator|+
operator|*
name|i
expr_stmt|;
block|}
comment|// check that we have all (and only) the expected files
name|qSort
argument_list|(
name|filesFound
argument_list|)
expr_stmt|;
name|qSort
argument_list|(
name|expectedFileNames
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|filesFound
argument_list|,
name|expectedFileNames
argument_list|)
expr_stmt|;
comment|// now actually check the file contents
name|QDir
name|directory
argument_list|(
name|baseDirectory
argument_list|)
decl_stmt|;
for|for
control|(
name|QStringMap
operator|::
name|const_iterator
name|i
init|=
name|expectedFiles
operator|.
name|constBegin
argument_list|()
init|;
name|i
operator|!=
name|expectedFiles
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|resourceFileName
init|=
name|i
operator|.
name|key
argument_list|()
decl_stmt|;
name|QString
name|actualFileName
init|=
name|i
operator|.
name|value
argument_list|()
decl_stmt|;
name|QFile
name|resourceFile
argument_list|(
name|resourceRootPrefix
operator|+
name|resourceFileName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|resourceFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|resourceData
init|=
name|resourceFile
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|resourceFile
operator|.
name|close
argument_list|()
expr_stmt|;
name|QFile
name|actualFile
argument_list|(
name|QFileInfo
argument_list|(
name|directory
argument_list|,
name|actualFileName
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|actualFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|actualData
init|=
name|actualFile
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|actualFile
operator|.
name|close
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|resourceData
argument_list|,
name|actualData
argument_list|)
expr_stmt|;
block|}
block|}
name|QVERIFY
argument_list|(
name|QResource
operator|::
name|unregisterResource
argument_list|(
name|resourceFile
argument_list|,
name|rootPrefix
argument_list|)
argument_list|)
expr_stmt|;
name|QLocale
operator|::
name|setDefault
argument_list|(
name|oldDefaultLocale
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_rcc
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|QString
name|dataPath
init|=
name|QFINDTESTDATA
argument_list|(
literal|"data/binary/"
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QDir
name|dataDir
argument_list|(
name|dataPath
argument_list|)
decl_stmt|;
name|QFileInfoList
name|entries
init|=
name|dataDir
operator|.
name|entryInfoList
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"*.rcc"
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QFileInfo
modifier|&
name|entry
decl|,
name|entries
control|)
name|QFile
operator|::
name|remove
argument_list|(
name|entry
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_rcc
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_rcc.moc"
end_include
end_unit
