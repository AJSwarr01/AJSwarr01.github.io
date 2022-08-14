/*Andrew Swarr
//SNHU CS-499
//JavaScript for MongoDB CRUD functions
*/

//Create
function create(data) {
	if(data == null) {
		print("No entry information provided.");
	}
	else if(db.listingsAndReviews.findOne(data) != null){
		print("Entry already exists.");
	}
	else{
		db.listingsAndReviews.insertOne(data);
		print("Successfully input listing!");
	}
}
//Read
function read(query, filter) {
	if(query == null){
		print("No input provided");
	}
	else if(db.listingsAndReviews.find(query, filter) == null){
		print("No listing found");
	}
	else{
		print(db.listingsAndReviews.find(query, filter));
	}
}
//Update
function update(query, data) {
	if(db.listingsAndReviews.findOne(query) == null){
		print("Listing does not exist.");
	}
	else if (data == null){
		print("No updated data provided.");
	}
	else{
		db.listingsAndReviews.updateOne(query, {$set: data});
		print("Successfully updated listing.");
	}
}
//Delete
function remove(query) {
	if(query == null) {
		print("No search criteria provided.");
	}
	else if(db.listingsAndReviews.findOne(query) == null){
		print("No listing found");
	}
	else{
		db.listingsAndReviews.deleteOne(query);
		print("Listing removed successfully.");
	}
}