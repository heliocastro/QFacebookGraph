#ifndef USERDATA_H
#define USERDATA_H

#include <QObject>

class QFacebookGraph;

class Userdata : public QObject {
	Q_OBJECT
	
	public:
	explicit Userdata(QObject *parent = 0);


	public slots:
		void requestDone( bool );

	private:
		QFacebookGraph *graph;
};

#endif
