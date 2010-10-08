#ifndef USERDATA_H
#define USERDATA_H

#include <QObject>
#include <qfacebookgraph.h>


class Userdata : public QFacebookGraph {
	Q_OBJECT
	
	public:
	explicit Userdata();


	public:
		void requestDone( bool ok = false );
};

#endif
