<script setup>
</script>

<template>
  <nav class="font-[Playfair_Display] bg-[#50C878] text-[#EDEADE]">
  <div class="flex flex-row mx-auto justify-between items-center">
  <h1 class="text-2xl">Learn.com</h1>
  <div class="flex space-x-4 mr-1">
    <router-link to="/">Home</router-link>
    <router-link to="/courses">Courses</router-link>
    <router-link to="/pricing">Pricing</router-link>
  </div>
  </div>
  </nav>
  <main>
    <router-view>Home</router-view>
  </main>
</template>

<style scoped>
</style>
