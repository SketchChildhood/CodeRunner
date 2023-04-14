// thread
use std::thread;
use std::time::Duration;

fn main() {
	let child = thread::spawn(move || {
		println!("{a} {b}", a = "Test1", b = "Test2");
	});
	
	let res = child.join();
	
	let t = thread::Builder::new()
			.name("child1".to_string())
			.spawn(move || {
				println!("enter child thread.");
				thread::park();
				println!("resume child thread.");
			}).unwrap();
	println!("spawn a thread.");
	thread::sleep(Duration::new(5, 0));
	t.thread().unpark();
	t.join();
	println!("child thread finished.");
}