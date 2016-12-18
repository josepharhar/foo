angular.module('hello', [])

  /*.controller('home', function($scope) {
    $scope.greeting = {id: 'xxx', content: 'Hello World!'}*/

  .controller('home', function($scope, $http) {
    $http.get('/resource/').success(function(data) {
      console.log("getting the thing: " + data);
      $scope.greeting = data;
    })

  })
