<template>
  <header class="bg-blue-800 text-white p-4 sticky top-0 shadow-md">
    <div class="container mx-auto flex justify-between items-start relative"> <!-- Added relative for positioning -->
      <h1 class="text-2xl font-bold">My Institute</h1>
      <button 
        class="md:hidden text-2xl" 
        @click="toggleMenu" 
        :aria-expanded="menuOpen" 
        aria-controls="mobile-menu"
      >
        <font-awesome-icon :icon="menuOpen ? 'times' : 'bars'" class="bg-blue-800" @click="toggleMenu"/>
      </button>
      <nav 
        id="mobile-menu"
        :class="[
          'md:space-x-4 md:flex md:static md:bg-transparent md:shadow-none',
          menuOpen ? 'flex flex-col absolute top-full left-0 right-0 bg-[honeydew] text-black  shadow-md border-[honeydew] rounded-md py-2 px-2 transition-all duration-100 ease-in-out' : 'hidden'
        ]"
      >
        <a href="#hero" class="hover:text-blue-500 block py-2">Home</a>
        <a href="#about" class="hover:text-blue-500 block py-2">About</a>
        <a href="#departments" class="hover:text-blue-500 block py-2">Departments</a>
        <a href="#courses" class="hover:text-blue-500 block py-2">Courses</a>
        <a href="#faculty" class="hover:text-blue-500 block py-2">Faculty</a>
        <a href="#campus" class="hover:text-blue-500 block py-2">Campus</a>
        <a href="#contact" class="hover:text-blue-500 block py-2">Contact</a>
      </nav>
    </div>
  </header>
</template>
<script setup>
import { ref } from 'vue';
const menuOpen = ref(false);
const toggleMenu = () => { menuOpen.value = !menuOpen.value; };
</script>
