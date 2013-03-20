begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 David Faure<faure@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qsavefile.h"
end_include
begin_include
include|#
directive|include
file|"private/qsavefile_p.h"
end_include
begin_include
include|#
directive|include
file|"qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qtemporaryfile.h"
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtemporaryfile_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSaveFilePrivate
name|QSaveFilePrivate
operator|::
name|QSaveFilePrivate
parameter_list|()
member_init_list|:
name|writeError
argument_list|(
name|QFileDevice
operator|::
name|NoError
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSaveFilePrivate
name|QSaveFilePrivate
operator|::
name|~
name|QSaveFilePrivate
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \class QSaveFile     \inmodule QtCore     \brief The QSaveFile class provides an interface for safely writing to files.      \ingroup io      \reentrant      \since 5.1      QSaveFile is an I/O device for writing text and binary files, without losing     existing data if the writing operation fails.      While writing, the contents will be written to a temporary file, and if     no error happened, commit() will move it to the final file. This ensures that     no data at the final file is lost in case an error happens while writing,     and no partially-written file is ever present at the final location. Always     use QSaveFile when saving entire documents to disk.      QSaveFile automatically detects errors while writing, such as the full partition     situation, where write() cannot write all the bytes. It will remember that     an error happened, and will discard the temporary file in commit().      Much like with QFile, the file is opened with open(). Data is usually read     and written using QDataStream or QTextStream, but you can also call the     QIODevice-inherited functions read(), readLine(), readAll(), write().      Unlike QFile, calling close() is not allowed. commit() replaces it. If commit()     was not called and the QSaveFile instance is destroyed, the temporary file is     discarded.      To abort saving due to an application error, call cancelWriting(), so that     even a call to commit() later on will not save.      \sa QTextStream, QDataStream, QFileInfo, QDir, QFile, QTemporaryFile */
end_comment
begin_comment
comment|/*!     Constructs a new file object with the given \a parent. */
end_comment
begin_constructor
DECL|function|QSaveFile
name|QSaveFile
operator|::
name|QSaveFile
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFileDevice
argument_list|(
operator|*
operator|new
name|QSaveFilePrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a new file object to represent the file with the given \a name. */
end_comment
begin_constructor
DECL|function|QSaveFile
name|QSaveFile
operator|::
name|QSaveFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|QFileDevice
argument_list|(
operator|*
operator|new
name|QSaveFilePrivate
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|fileName
operator|=
name|name
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a new file object with the given \a parent to represent the     file with the specified \a name. */
end_comment
begin_constructor
DECL|function|QSaveFile
name|QSaveFile
operator|::
name|QSaveFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFileDevice
argument_list|(
operator|*
operator|new
name|QSaveFilePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|fileName
operator|=
name|name
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the file object, discarding the saved contents unless commit() was called. */
end_comment
begin_destructor
DECL|function|~QSaveFile
name|QSaveFile
operator|::
name|~
name|QSaveFile
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
name|QFileDevice
operator|::
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|fileEngine
condition|)
block|{
name|d
operator|->
name|fileEngine
operator|->
name|remove
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|fileEngine
expr_stmt|;
name|d
operator|->
name|fileEngine
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Returns the name set by setFileName() or to the QSaveFile     constructor.      \sa setFileName() */
end_comment
begin_function
DECL|function|fileName
name|QString
name|QSaveFile
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|fileName
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the \a name of the file. The name can have no path, a     relative path, or an absolute path.      \sa QFile::setFileName(), fileName() */
end_comment
begin_function
DECL|function|setFileName
name|void
name|QSaveFile
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|fileName
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Opens the file using OpenMode \a mode, returning true if successful;     otherwise false.      Important: the \a mode must include QIODevice::WriteOnly.     It may also have additional flags, such as QIODevice::Text and QIODevice::Unbuffered.      QIODevice::ReadWrite and QIODevice::Append are not supported at the moment.      \sa QIODevice::OpenMode, setFileName() */
end_comment
begin_function
DECL|function|open
name|bool
name|QSaveFile
operator|::
name|open
parameter_list|(
name|OpenMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|isOpen
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSaveFile::open: File (%s) already open"
argument_list|,
name|qPrintable
argument_list|(
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|unsetError
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|mode
operator|&
operator|(
name|ReadOnly
operator||
name|WriteOnly
operator|)
operator|)
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSaveFile::open: Open mode not specified"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// In the future we could implement ReadWrite by copying from the existing file to the temp file...
if|if
condition|(
operator|(
name|mode
operator|&
name|ReadOnly
operator|)
operator|||
operator|(
name|mode
operator|&
name|Append
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSaveFile::open: Unsupported open mode 0x%x"
argument_list|,
name|int
argument_list|(
name|mode
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// check if existing file is writable
name|QFileInfo
name|existingFile
argument_list|(
name|d
operator|->
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|existingFile
operator|.
name|exists
argument_list|()
operator|&&
operator|!
name|existingFile
operator|.
name|isWritable
argument_list|()
condition|)
block|{
name|d
operator|->
name|setError
argument_list|(
name|QFileDevice
operator|::
name|WriteError
argument_list|,
name|QSaveFile
operator|::
name|tr
argument_list|(
literal|"Existing file %1 is not writable"
argument_list|)
operator|.
name|arg
argument_list|(
name|d
operator|->
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|writeError
operator|=
name|QFileDevice
operator|::
name|WriteError
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|fileEngine
operator|=
operator|new
name|QTemporaryFileEngine
argument_list|(
name|d
operator|->
name|fileName
argument_list|)
expr_stmt|;
comment|// Same as in QFile: QIODevice provides the buffering, so there's no need to request it from the file engine.
if|if
condition|(
operator|!
name|d
operator|->
name|fileEngine
operator|->
name|open
argument_list|(
name|mode
operator||
name|QIODevice
operator|::
name|Unbuffered
argument_list|)
condition|)
block|{
name|QFileDevice
operator|::
name|FileError
name|err
init|=
name|d
operator|->
name|fileEngine
operator|->
name|error
argument_list|()
decl_stmt|;
if|if
condition|(
name|err
operator|==
name|QFileDevice
operator|::
name|UnspecifiedError
condition|)
name|err
operator|=
name|QFileDevice
operator|::
name|OpenError
expr_stmt|;
name|d
operator|->
name|setError
argument_list|(
name|err
argument_list|,
name|d
operator|->
name|fileEngine
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|fileEngine
expr_stmt|;
name|d
operator|->
name|fileEngine
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QFileDevice
operator|::
name|open
argument_list|(
name|mode
argument_list|)
expr_stmt|;
if|if
condition|(
name|existingFile
operator|.
name|exists
argument_list|()
condition|)
name|setPermissions
argument_list|(
name|existingFile
operator|.
name|permissions
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp   This method has been made private so that it cannot be called, in order to prevent mistakes.   In order to finish writing the file, call commit().   If instead you want to abort writing, call cancelWriting(). */
end_comment
begin_function
DECL|function|close
name|void
name|QSaveFile
operator|::
name|close
parameter_list|()
block|{
name|qFatal
argument_list|(
literal|"QSaveFile::close called"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Commits the changes to disk, if all previous writes were successful.    It is mandatory to call this at the end of the saving operation, otherwise the file will be   discarded.    If an error happened during writing, deletes the temporary file and returns false.   Otherwise, renames it to the final fileName and returns true on success.   Finally, closes the device.    \sa cancelWriting() */
end_comment
begin_function
DECL|function|commit
name|bool
name|QSaveFile
operator|::
name|commit
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fileEngine
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|isOpen
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSaveFile::commit: File (%s) is not open"
argument_list|,
name|qPrintable
argument_list|(
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QFileDevice
operator|::
name|close
argument_list|()
expr_stmt|;
comment|// calls flush()
comment|// Sync to disk if possible. Ignore errors (e.g. not supported).
name|d
operator|->
name|fileEngine
operator|->
name|syncToDisk
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|writeError
operator|!=
name|QFileDevice
operator|::
name|NoError
condition|)
block|{
name|d
operator|->
name|fileEngine
operator|->
name|remove
argument_list|()
expr_stmt|;
name|d
operator|->
name|writeError
operator|=
name|QFileDevice
operator|::
name|NoError
expr_stmt|;
operator|delete
name|d
operator|->
name|fileEngine
expr_stmt|;
name|d
operator|->
name|fileEngine
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// atomically replace old file with new file
comment|// Can't use QFile::rename for that, must use the file engine directly
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|fileEngine
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fileEngine
operator|->
name|renameOverwrite
argument_list|(
name|d
operator|->
name|fileName
argument_list|)
condition|)
block|{
name|d
operator|->
name|setError
argument_list|(
name|d
operator|->
name|fileEngine
operator|->
name|error
argument_list|()
argument_list|,
name|d
operator|->
name|fileEngine
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|fileEngine
operator|->
name|remove
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|fileEngine
expr_stmt|;
name|d
operator|->
name|fileEngine
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|delete
name|d
operator|->
name|fileEngine
expr_stmt|;
name|d
operator|->
name|fileEngine
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!   Cancels writing the new file.    If the application changes its mind while saving, it can call cancelWriting(),   which sets an error code so that commit() will discard the temporary file.    Alternatively, it can simply make sure not to call commit().    Further write operations are possible after calling this method, but none   of it will have any effect, the written file will be discarded.    \sa commit() */
end_comment
begin_function
DECL|function|cancelWriting
name|void
name|QSaveFile
operator|::
name|cancelWriting
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isOpen
argument_list|()
condition|)
return|return;
name|d
operator|->
name|setError
argument_list|(
name|QFileDevice
operator|::
name|WriteError
argument_list|,
name|QSaveFile
operator|::
name|tr
argument_list|(
literal|"Writing canceled by application"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|writeError
operator|=
name|QFileDevice
operator|::
name|WriteError
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|writeData
name|qint64
name|QSaveFile
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSaveFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|writeError
operator|!=
name|QFileDevice
operator|::
name|NoError
condition|)
return|return
operator|-
literal|1
return|;
specifier|const
name|qint64
name|ret
init|=
name|QFileDevice
operator|::
name|writeData
argument_list|(
name|data
argument_list|,
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|error
operator|!=
name|QFileDevice
operator|::
name|NoError
condition|)
name|d
operator|->
name|writeError
operator|=
name|d
operator|->
name|error
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
