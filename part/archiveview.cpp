/*
 * ark -- archiver for the KDE project
 *
 * Copyright (C) 2008 Harald Hvaal <haraldhv (at@at) stud.ntnu.no>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include "archiveview.h"
#include <QHeaderView>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <kdebug.h>


ArchiveView::ArchiveView(QWidget *parent)
	: QTreeView(parent)
{
	setSelectionMode( QAbstractItemView::ExtendedSelection );
	setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	setAlternatingRowColors( true );
	setAnimated( true );
	header()->setResizeMode(0, QHeaderView::ResizeToContents);
	setAllColumnsShowFocus( true );

	//drag and drop
	setDragEnabled(true);
	setAcceptDrops(true);
	setDropIndicatorShown(true);
	setDragDropMode(QAbstractItemView::DragDrop);

}

void ArchiveView::dragEnterEvent ( QDragEnterEvent * event )
{
	//TODO: if no model, trigger some mechanism to create one automatically!
	if (!model()) return;
	if (event->mimeData()->hasFormat("text/uri-list"))
         event->acceptProposedAction();
}

void ArchiveView::dragMoveEvent ( QDragMoveEvent * event )
{
	if (!model()) return;
	kDebug() << indexAt(event->pos());
	event->acceptProposedAction();
}
