from time import sleep
import socketio



sio = socketio.Client()

@sio.event
def connect():
    print('connection established')

@sio.event
def my_message(data):
    print('message received with ', data)
    sio.emit('client response', {'response': 'client response'})

@sio.on('server_response')
def on_server_response(data):
    print(f"I received a server message! {data}")

@sio.event
def disconnect():
    print('disconnected from server')

sio.connect('http://127.0.0.1:5000')

for i in range(10):
    print('send message' + ' ' + str(i))
    sleep(1)
    sio.emit('number_event', {'a': str(i)})

sio.wait()
