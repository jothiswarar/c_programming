import sqlite3

def connect_database(database_name):
    """Connects to an SQLite database and returns a connection object."""
    try:
        connection = sqlite3.connect(database_name)
        return connection
    except sqlite3.Error as e:
        print(f"Error connecting to database: {e}")
        return None

def execute_query(connection, query):
    """Executes a given SQL query on the specified connection."""
    try:
        cursor = connection.cursor()
        cursor.execute(query)
        if query.upper().startswith("SELECT"):
            results = cursor.fetchall()
            for row in results:
                print(row)
        else:
            connection.commit()
            print("Query executed successfully.")
    except sqlite3.Error as e:
        print(f"Error executing query: {e}")

def main():
    """Prompts the user for database name and queries, executing them."""
    database_name = input("Enter the SQLite database name: ")
    connection = connect_database(database_name)
    if connection:
        while True:
            query = input("Enter your SQL query (or 'exit' to quit): ")
            if query.lower() == "exit":
                break
            execute_query(connection, query)
        connection.close()
        print("Connection closed.")

if __name__ == "__main__":
    main()
