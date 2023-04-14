import select
import eventlet
import socketio

eventlet.monkey_patch()

sio = socketio.Server()
app = socketio.WSGIApp(sio)

@sio.event
def connect(sid, environ):
    print('connect ', sid)

@sio.event
def disconnect(sid):
    print('disconnect ', sid)

@sio.event
def my_message(sid, data):
    print('message ', data)
    sio.emit('server response', {'response': 'server response'})


@sio.on('number_event')
def on_number_event(sid, data):
    print(f"I received a client message! {sid} : {data}")
    sio.emit('server_response', {'response': 'server response'})

if __name__ == '__main__':
    # export EVENTLET_HUB=poll
    eventlet.wsgi.server(eventlet.listen(('127.0.0.1', 5000)), app)
