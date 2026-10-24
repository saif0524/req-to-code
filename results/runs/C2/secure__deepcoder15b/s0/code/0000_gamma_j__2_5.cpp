#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

string
string is declared in the file

string;
string;
string;
string;
string;

public function string($columns = ['name', 'age']) => string {
  $connection = $this->getDatabaseConnection();
  if (!is_string($columns))
    throw new Exception('Columns must be a string array');

  $query = $connection->execute('SELECT $columns');
  try
    if ($connection && $connection->connect($query))
      $result = $connection->execute($query);
      if ($result && $result->select($columns))
        $data = $result->select($columns)->get()[0];
        return $data;
    }
    return 'No data found';
  }
  return 'No operation performed';
}

public function string(string $table, string $columns = ['name', 'age']) => string {
  let connection = $this->getDatabaseConnection();
  let result;

  if (connection && connection->connect('test')) {
    $result = connection->execute('UPDATE $table SET $columns = ['name', 'age']');
    if ($result && $result->select($columns)) {
      $data = $result->select($columns)->get()[0];
      return $data;
    }
  }

  if (connection && connection->execute('SELECT $columns FROM $table')) {
    $query = connection->execute('SELECT $columns FROM $table');
    $result = connection->execute('INSERT INTO $table ($columns) VALUES(' . implode(',', $query) . ')');
    $result = connection->execute('SELECT $columns');
    $data = $result->execute('SELECT $columns');
    $data = $data->get()[0];
    return $data;
  }

  return 'No operation performed';
}

public function string($columns = ['name', 'age']) => string {
  if (!is_string($columns)) {
    throw new Exception('Columns must be a string array');
  }
  if ($columns === ['name', 'age']) {
    return 'Update table with default values';
  } else if ($columns === ['name', 'age']) {
    return 'Update table with specified columns';
  } else if ($columns === ['name', 'age']) {
    return 'Update table with custom columns';
  } else if ($columns === ['name', 'age']) {
    return 'Insert table with default values';
  } else if ($columns === ['name', 'age']) {
    return 'Insert table with specified columns';
  } else if ($columns === ['name', 'age']) {
    return 'Delete table';
  }
  return 'No operation performed';
  }

string(string $table, string $columns = ['name', 'age']) => string {
  let connection = $this->getDatabaseConnection();
  let result;
  if (connection && connection->connect('test')) {
    $result = connection->execute('UPDATE $table SET $columns = ['name', 'age']');
    if ($result && $result->select($columns)) {
      $data = $result->select($columns)->get()[0];
      return $data;
    }
  }
  if (connection && connection->execute('SELECT $columns FROM $table')) {
    $query = connection->execute('SELECT $columns FROM $table');
    $result = connection->execute('INSERT INTO $table ($columns) VALUES(' . implode(',', $query) . ')');
    $result = connection->execute('SELECT $columns');
    $data = $result->execute('SELECT $columns');
    $data = data->get()[0];
    return $data;
  }
  return 'No data found';
  }
  "}

string(string $columns = ['name', 'age']) => string {
  let connection = $this->getDatabaseConnection();
  if (!is_string($columns)) {
    throw new Exception('Columns must be a string array');
  }
  if (connection && connection->connect('test')) {
    $result = connection->execute('UPDATE $table SET $columns = ['name', 'age']');
    if ($result && $result->select($columns)) {
      $data = $result->select($columns)->get()[0];
      return $data;
    }
  }
  if (connection && connection->execute('SELECT $columns FROM $table')) {
    $query = connection->execute('SELECT $columns FROM $table');
    $result = connection->execute('INSERT INTO $table ($columns) VALUES(' . implode(',', $query) . ')');
    $result = connection->execute('SELECT $columns');
    $data = $result->execute('SELECT $columns');
    $data = data->get()[0];
    return $data;
  }
  return 'No operation performed';
  }
  "}

